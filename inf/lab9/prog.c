/*
Практическая работа: «Моделирование архитектуры фон Неймана на языке С».
Вариант 1, уровень «отлично».

Как программа отражает принципы архитектуры фон Неймана:
  1. Единая память. И команды, и данные лежат в одном массиве memory[]
    и различаются только тем, как процессор их использует.
  2. Счётчик команд. Ячейка cpu_state[0] (pc) хранит адрес следующей
    команды; после каждой команды pc меняется (+2 или переход).
  3. Последовательное выполнение. Цикл while повторяет такт процессора:
    выборка команды -> проверка -> исполнение.
  4. Регистры и АЛУ. Аккумулятор cpu_state[1] хранит результат,
    регистр команд cpu_state[2] - текущий опкод; арифметика (умножение
    и деление) выполняется в execute_command().

Система команд (после кода команды 1-5 в следующей ячейке стоит адрес):
   0 - STOP
   1 - LOAD: acc = memory[адрес]
   2 - MUL:  acc = acc * memory[адрес]
   3 - DIV:  acc = acc / memory[адрес] (деление на 0 - прерывание)
   4 - JUMP: pc = адрес
   5 - JZ:   если acc == 0, то pc = адрес, иначе pc = pc + 2

Запуск через перенаправление потока ввода из файла:
   ./prog < program.txt

Формат program.txt: первое число - вектор прерываний (memory[0]),
далее числа записываются в memory[1], memory[2], ... Выполнение
начинается с адреса START_PC.

Обработка ошибок: код ошибки кладётся в cpu_state[5], процессор
останавливается, а сообщение выводит main() через print_error().
*/




/* ----------------Препроцссоры------------------ */

#include <stdio.h>


#define MEMORY_SIZE    256
#define CPU_STATE_SIZE 8
#define START_PC       1    /* адрес первой выполняемой команды */

/* назначение ячеек массива cpu_state */
#define CPU_PC   0   /* счётчик команд */
#define CPU_ACC  1   /* аккумулятор */
#define CPU_IR   2   /* регистр команд */
#define CPU_VEC  3   /* вектор прерываний */
#define CPU_STOP 4   /* флаг остановки */
#define CPU_ERR  5   /* код последней ошибки */

/* ошибки во время выполнения */
#define ERR_NONE        0   /* ошибок нет */
#define ERR_MEMORY      1   /* выход за границы памяти */
#define ERR_OPCODE      2   /* неизвестная команда */
#define ERR_DIV_ZERO    3   /* деление на ноль */
#define ERR_NO_OPERAND  4   /* нет операнда */

/* ошибки при чтении программы */
#define ERR_INPUT_EMPTY 5   /* пустой ввод */
#define ERR_INPUT_BAD   6   /* во вводе не целое число */
#define ERR_VECTOR      7   /* вектор прерываний вне памяти */
#define ERR_INPUT_BIG   8   /* во вводе больше 256 чисел */
#define ERR_NO_PROGRAM  9   /* во вводе нет команд */





/* -------------Основные функции программы------- */

/* чтение программы из ввода и инициализация процессора */
void load_program(int cpu_state[], int memory[]);
void init_cpu(int cpu_state[], int memory[]);

/* работа  процессора */
void run_cpu(int cpu_state[], int memory[]);

/* проверки при работе с данными */
int in_memory(int address);
int fetch_command(int cpu_state[], int memory[]);
int check_operand(int cpu_state[], int memory[]);

/* выборщик команды исполнения */
void execute_command(int cpu_state[], int memory[]);

/* команды исполнения */
void cmd_load(int cpu_state[], int operand, int addr);
void cmd_mul(int cpu_state[], int operand, int addr);
void cmd_div(int cpu_state[], int operand, int addr);
void cmd_jump(int cpu_state[], int addr);
void cmd_jz(int cpu_state[], int addr);




/* ------------------Ошибки------------------------ */

/* выборщик ошибки */
void print_error(int cpu_state[], int memory[]);


/* специализированные ошибки */
void err_memory(int cpu_state[], int memory[]);
void err_opcode(int cpu_state[]);
void err_div_zero(int cpu_state[], int memory[]);
void err_no_operand(int cpu_state[]);
void err_input(int cpu_state[], int memory[]);





/* ----------------Точка входа-------------------- */

int main(void) {
    int cpu_state[CPU_STATE_SIZE] = {0};
    int memory[MEMORY_SIZE] = {0};

    load_program(cpu_state, memory);

    if (cpu_state[CPU_ERR] == ERR_NONE) {
        init_cpu(cpu_state, memory);
    }
    
    if (cpu_state[CPU_ERR] == ERR_NONE) {
        run_cpu(cpu_state, memory);
    }

    if (cpu_state[CPU_ERR] != ERR_NONE) {
        print_error(cpu_state, memory);
        return 1;
    }

    printf("Программа завершена.\n");
    return 0;
}




/* -----------------------Загрузчик данных------------------ */

void load_program(int cpu_state[], int memory[]) {
    int value;
    int count;
    int read_result;

    /* первое число - вектор прерываний, читаем его отдельно */
    read_result = scanf("%d", &value);
    if (read_result == EOF) {
        cpu_state[CPU_ERR] = ERR_INPUT_EMPTY;
        return;
    }
    if (read_result != 1) {
        cpu_state[CPU_ERR] = ERR_INPUT_BAD;
        return;
    }

    memory[0] = value;
    if (!in_memory(value)) {
        cpu_state[CPU_ERR] = ERR_VECTOR;
        return;
    }

    /* остальные числа - в память, пока они есть и есть место */
    count = 1;
    read_result = scanf("%d", &value);
    while (read_result == 1 && count < MEMORY_SIZE) {
        memory[count] = value;
        count++;
        read_result = scanf("%d", &value);
    }

    if (read_result == 0) {
        cpu_state[CPU_ERR] = ERR_INPUT_BAD;
    } else if (read_result == 1) {
        cpu_state[CPU_ERR] = ERR_INPUT_BIG;
    } else if (count <= START_PC) {
        cpu_state[CPU_ERR] = ERR_NO_PROGRAM;
    }
}


void init_cpu(int cpu_state[], int memory[]) {
    cpu_state[CPU_PC] = START_PC;
    cpu_state[CPU_ACC] = 0;
    cpu_state[CPU_IR] = 0;
    cpu_state[CPU_VEC] = memory[0];
    cpu_state[CPU_STOP] = 0;
    cpu_state[CPU_ERR] = ERR_NONE;

    /* память под расширения состаяний процессора */
    cpu_state[6] = 0;
    cpu_state[7] = 0;
}







/* ----------------Проверки набора данных----------------- */

/* Возвращает 1, если адрес лежит внутри памяти, иначе 0 */
int in_memory(int address) {
    return address >= 0 && address < MEMORY_SIZE;
}

/* Проверка правильности команды (его принадлежность 0-5).
   Возвращает код ошибки или ERR_NONE */
int fetch_command(int cpu_state[], int memory[]) {
    if (!in_memory(cpu_state[CPU_PC])) {
        return ERR_MEMORY;
    }

    cpu_state[CPU_IR] = memory[cpu_state[CPU_PC]];
    if (cpu_state[CPU_IR] < 0 || cpu_state[CPU_IR] > 5) {
        return ERR_OPCODE;
    }

    return ERR_NONE;
}

/* Проверяет операнд команды 1-5
   Возвращает код ошибки или ERR_NONE */
int check_operand(int cpu_state[], int memory[]) {
    int addr;

    if (cpu_state[CPU_IR] == 0) {
        return ERR_NONE;            /* у STOP операнда нет */
    }

    if (!in_memory(cpu_state[CPU_PC] + 1)) {
        return ERR_NO_OPERAND;      /* команда в последней ячейке */
    }

    addr = memory[cpu_state[CPU_PC] + 1];
    if (!in_memory(addr)) {
        return ERR_MEMORY;
    }
    if (cpu_state[CPU_IR] == 3 && memory[addr] == 0) {
        return ERR_DIV_ZERO;
    }

    return ERR_NONE;
}

/* ---------------------Исполнение команд------------------------ */


/* Загрузка данных (комманда 1) */
void cmd_load(int cpu_state[], int operand, int addr){
    cpu_state[CPU_ACC] = operand;

    printf("pc=%d: команда 1 (load), operand=%d (адрес %d), acc=%d\n",
           cpu_state[CPU_PC], operand, addr, cpu_state[CPU_ACC]);

    cpu_state[CPU_PC] += 2;
}

/* Умножение (комманда 2) */
void cmd_mul(int cpu_state[], int operand, int addr){
    cpu_state[CPU_ACC] = cpu_state[CPU_ACC] * operand;

    printf("pc=%d: команда 2 (mul), operand=%d (адрес %d), acc=%d\n",
           cpu_state[CPU_PC], operand, addr, cpu_state[CPU_ACC]);

    cpu_state[CPU_PC] += 2;
}

/* деление (комманда 3) */
void cmd_div(int cpu_state[], int operand, int addr){
    cpu_state[CPU_ACC] = cpu_state[CPU_ACC] / operand;

    printf("pc=%d: команда 3 (div), operand=%d (адрес %d), acc=%d\n",
           cpu_state[CPU_PC], operand, addr, cpu_state[CPU_ACC]);

    cpu_state[CPU_PC] += 2;
}

/* безусловный переход (комманда 4) */
void cmd_jump(int cpu_state[], int addr){
    printf("pc=%d: команда 4 (JUMP), адрес=%d, acc=%d\n",
           cpu_state[CPU_PC], addr, cpu_state[CPU_ACC]);

    cpu_state[CPU_PC] = addr;
}

/* условный переход при acc = 0 (комманда 5) */
void cmd_jz(int cpu_state[], int addr){
    if (cpu_state[CPU_ACC] == 0) {
        printf("pc=%d: команда 5 (JZ), адрес=%d, переход выполнен, acc=%d\n",
               cpu_state[CPU_PC], addr, cpu_state[CPU_ACC]);
        cpu_state[CPU_PC] = addr;
    } else {
        printf("pc=%d: команда 5 (JZ), адрес=%d, переход не выполнен, acc=%d\n",
               cpu_state[CPU_PC], addr, cpu_state[CPU_ACC]);
        cpu_state[CPU_PC] += 2;
    }
}

/* выборщик комманды */
void execute_command(int cpu_state[], int memory[]){
    int opperand, addr;

    if(cpu_state[CPU_IR] == 0) {
        printf("pc=%d: команда 0 (STOP), acc=%d\n", cpu_state[CPU_PC],
            cpu_state[CPU_ACC]);
        cpu_state[CPU_STOP] = 1;
        return;
    }

    addr = memory[cpu_state[CPU_PC] + 1];
    opperand = memory[addr];

    switch (cpu_state[CPU_IR]) {
        case 1: cmd_load(cpu_state, opperand, addr); break;
        case 2: cmd_mul (cpu_state, opperand, addr); break;
        case 3: cmd_div (cpu_state, opperand, addr); break;
        case 4: cmd_jump(cpu_state, addr); break;
        case 5: cmd_jz  (cpu_state, addr); break;
        default: 
            cpu_state[CPU_STOP] = 1;
            print_error(cpu_state, memory);
            break;
    }
}







/* ---------------------Основной цикл работы-------------------- */


void run_cpu(int cpu_state[], int memory[]) {
    while (cpu_state[CPU_STOP] == 0) {
        cpu_state[CPU_ERR] = fetch_command(cpu_state, memory);
        if (cpu_state[CPU_ERR] == ERR_NONE) {
            cpu_state[CPU_ERR] = check_operand(cpu_state, memory);
        }

        if (cpu_state[CPU_ERR] != ERR_NONE) {
            cpu_state[CPU_STOP] = 1;
            return;
        }

        execute_command(cpu_state, memory);
    }
}








/* ------------------------Вывод Ошибок------------------------------*/

/* Выбирает функцию вывода по коду ошибки из cpu_state[CPU_ERR] */
void print_error(int cpu_state[], int memory[]) {
    switch (cpu_state[CPU_ERR]) {
        case ERR_MEMORY:
            err_memory(cpu_state, memory);
            break;
        case ERR_OPCODE:
            err_opcode(cpu_state);
            break;
        case ERR_DIV_ZERO:
            err_div_zero(cpu_state, memory);
            break;
        case ERR_NO_OPERAND:
            err_no_operand(cpu_state);
            break;
        case ERR_INPUT_EMPTY:
        case ERR_INPUT_BAD:
        case ERR_VECTOR:
        case ERR_INPUT_BIG:
        case ERR_NO_PROGRAM:
            err_input(cpu_state, memory);
            break;
        default:
            printf("ОШИБКА: неизвестный код %d\n", cpu_state[CPU_ERR]);
            break;
    }

    printf("Программа завершена с ошибкой. Код ошибки: %d\n",
           cpu_state[CPU_ERR]);
}

/* ошибки программы (коды 1-4)*/

void err_memory(int cpu_state[], int memory[]) {
    if (!in_memory(cpu_state[CPU_PC])) {
        printf("pc=%d: ОШИБКА: выход за границы памяти\n",
               cpu_state[CPU_PC]);
    } else {
        printf("pc=%d: команда %d, адрес=%d, ОШИБКА: адрес вне памяти\n",
               cpu_state[CPU_PC], cpu_state[CPU_IR],
               memory[cpu_state[CPU_PC] + 1]);
    }
}


void err_opcode(int cpu_state[]) {
    printf("pc=%d: ОШИБКА: неизвестная команда %d\n",
           cpu_state[CPU_PC], cpu_state[CPU_IR]);
}


void err_div_zero(int cpu_state[], int memory[]) {
    printf("pc=%d: команда 3, operand=%d, ОШИБКА: деление на 0\n",
           cpu_state[CPU_PC], memory[memory[cpu_state[CPU_PC] + 1]]);
}


void err_no_operand(int cpu_state[]) {
    printf("pc=%d: команда %d, ОШИБКА: нет операнда\n",
           cpu_state[CPU_PC], cpu_state[CPU_IR]);
}


/* Ошибки чтения программы (коды 5-9) */


void err_input(int cpu_state[], int memory[]) {
    switch (cpu_state[CPU_ERR]) {
        case ERR_INPUT_EMPTY:
            printf("ОШИБКА: пустой ввод данных\n");
            break;
        case ERR_INPUT_BAD:
            printf("ОШИБКА: во вводе встретилось не целое число\n");
            break;
        case ERR_VECTOR:
            printf("ОШИБКА: вектор прерываний %d вне диапазона 0..%d\n",
                   memory[0], MEMORY_SIZE - 1);
            break;
        case ERR_INPUT_BIG:
            printf("ОШИБКА: во вводе больше %d чисел\n", MEMORY_SIZE);
            break;
        default:
            printf("ОШИБКА: во вводе нет ни одной команды\n");
            break;
    }
}
