/**
 * @brief It implements the command interpreter
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 19-12-2014
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H
/*Acciones que el usuario puede realizar: le hemos añadido PICK DROP, ROLL, LEFT Y RIGHT*/
/*
Añadimos 2 nuevos comandos correspondientes con las teclas c y d, que se corresponden con coger y dejar el objeto
Sumamos 2 por lo tanto a N_CMD*/
#define CMD_LENGHT 30
#define N_CMD 10

typedef enum enum_Command {
  NO_CMD = -1,
  UNKNOWN,
  EXIT,
  FOLLOWING,
  PREVIOUS,
  GRASP,
  DROP,
  ROLL,
  LEFT,
  RIGHT
} T_Command;

extern char* cmd_to_str[N_CMD];
T_Command command_get_user_input();

#endif
