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
/*Acciones que el usuario puede realizar: le hemos añadido PICK y DROP*/
typedef enum enum_Command {
  NO_CMD = -1, 
  UNKNOWN, 
  EXIT, 
  FOLLOWING, 
  PREVIOUS,
  PICK,
  DROP
} T_Command;


T_Command get_user_input();

#endif
