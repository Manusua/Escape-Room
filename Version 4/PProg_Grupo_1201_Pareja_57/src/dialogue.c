/**
 * @brief En este fichero implementamos las funciones del dialogo
 * @file dialogue.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @version 1.0
 * @date 16/12/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "types.h"
#include "game.h"
#include "command.h"

/**
 * @brief imprime la descripcion de la acción
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 16/12/2018
 * @param command comando que se acaba de ejecutar
 * @param prev_cmd comando previo
 * @param prev_stat true si se ha podido ejecutar el comando anterior
 * @param act_stat resultado de la ejecucion del comando
 * @param aux cadena donde se imprime el resultado
 * @return OK o ERROR
 */
STATUS dialogue_action(Command *command, T_Command prev_cmd, STATUS prev_stat, STATUS act_stat, char * aux) {
    T_Command cmd = NO_CMD;
    char *parte = NULL;
    if (!aux || !command) return ERROR;
    cmd = command_get_command(command);
    if (cmd == prev_cmd && !prev_stat) {
        strcat(aux, "Ya has hecho esto antes sin exito, prueba algo diferente.");
        return OK;
    }
    if (act_stat == OK) {
        switch (cmd) {
            case NO_CMD: strcat(aux, "Ningun comando seleccionado.");
                break;
            case UNKNOWN: strcat(aux, "No se ha reconocido el comando.");
                break;
            case QUIT: strcat(aux, "Has salido del juego.");
                break;
            case GO: strcat(aux, "Has ido ");
                if (strcasecmp(command_get_name(command), "north") == 0 || strcasecmp(command_get_name(command), "n") == 0) strcat(aux, "al norte.");
                if (strcasecmp(command_get_name(command), "south") == 0 || strcasecmp(command_get_name(command), "s") == 0) strcat(aux, "al sur.");
                if (strcasecmp(command_get_name(command), "east") == 0 || strcasecmp(command_get_name(command), "e") == 0) strcat(aux, "al este.");
                if (strcasecmp(command_get_name(command), "west") == 0 || strcasecmp(command_get_name(command), "w") == 0) strcat(aux, "al oeste.");
                if (strcasecmp(command_get_name(command), "up") == 0 || strcasecmp(command_get_name(command), "u") == 0) strcat(aux, "arriba.");
                if (strcasecmp(command_get_name(command), "down") == 0 || strcasecmp(command_get_name(command), "d") == 0) strcat(aux, "abajo.");
                break;
            case TAKE: strcat(aux, "Has cogido el objeto ");
		if(command_get_name(command)==NULL) return ERROR;
                strcat(aux, command_get_name(command));
                break;
            case LEAVE: strcat(aux, "Has dejado el objeto ");
		if(command_get_name(command)==NULL) return ERROR;
                strcat(aux, command_get_name(command));
                break;
            case ROLL: strcat(aux, "Has tirado el dado.");
                break;
            case INSPECT: strcat(aux, "Has examinado el objeto  ");
		if(command_get_name(command)==NULL) return ERROR;
                strcat(aux, command_get_name(command));
                break;
            case FOLLOWING: strcat(aux, "Has seleccionado seguir (ir al sur).");
                break;
            case PREVIOUS: strcat(aux, "Has seleccionado retroceder (ir al norte).");
                break;
            case GOOSE_FOLLOWING: strcat(aux, "Has seleccionado oca (ir al oeste).");
                break;
            case GOOSE_PREVIOUS: strcat(aux, "Has seleccionado oca hacia atras (ir al este).");
                break;
            case TURNON: strcat(aux, "Has encendido el objeto ");
		if(command_get_name(command)==NULL) return ERROR;
                strcat(aux, command_get_name(command));
                break;
            case TURNOFF: strcat(aux, "Has apagado el objeto ");
		if(command_get_name(command)==NULL) return ERROR;
                strcat(aux, command_get_name(command));
                break;
            case LOAD:
                strcat(aux, "Has cargado un juego guardado.");
                break;
            case SAVE:
                strcat(aux, "Has guardado un juego.");
                break;
            case OPEN:
                strcat(aux, "Has abierto ");
		if(command_get_name(command)==NULL) return ERROR;
                parte = strtok(command_get_name(command), " \n");
		if(parte==NULL) return ERROR;
                strcat(aux, parte);
                strcat(aux, " con ");
                parte = strtok(NULL, " \n");
                strcat(aux, parte);
                break;
            default: strcat(aux, "Comando no reconocido");
        }
    } else {
        switch (cmd) {
            case NO_CMD: strcat(aux, "Ningun comando seleccionado.");
                break;
            case UNKNOWN: strcat(aux, "No se ha reconocido el comando.");
                break;
            case QUIT: strcat(aux, "Has intentado salir del juego sin exito.");
                break;
            case GO: strcat(aux, "Has tratado de ir ");
                if (strcasecmp(command_get_name(command), "north") == 0 || strcasecmp(command_get_name(command), "n") == 0) strcat(aux, "al norte sin exito.");
                if (strcasecmp(command_get_name(command), "south") == 0 || strcasecmp(command_get_name(command), "s") == 0) strcat(aux, "al sur sin exito.");
                if (strcasecmp(command_get_name(command), "east") == 0 || strcasecmp(command_get_name(command), "e") == 0) strcat(aux, "al este sin exito.");
                if (strcasecmp(command_get_name(command), "west") == 0 || strcasecmp(command_get_name(command), "w") == 0) strcat(aux, "al oeste sin exito.");
                if (strcasecmp(command_get_name(command), "up") == 0 || strcasecmp(command_get_name(command), "u") == 0) strcat(aux, "arriba sin exito.");
                if (strcasecmp(command_get_name(command), "down") == 0 || strcasecmp(command_get_name(command), "d") == 0) strcat(aux, "abajo sin exito.");
                break;
            case TAKE: strcat(aux, "No has podido coger el objeto ");
		if(command_get_name(command)==NULL) return ERROR;
                strcat(aux, command_get_name(command));
                break;
            case LEAVE: strcat(aux, "No has podido soltar objeto ");
		if(command_get_name(command)==NULL) return ERROR;
                strcat(aux, command_get_name(command));
                break;
            case ROLL: strcat(aux, "No has podido tirar el dado.");
                break;
            case INSPECT: strcat(aux, "No has logrado examinar el objeto ");
		if(command_get_name(command)==NULL) return ERROR;
                strcat(aux, command_get_name(command));
                break;
            case FOLLOWING: strcat(aux, "No has podido seguir (ir al sur).");
                break;
            case PREVIOUS: strcat(aux, "No has podido retroceder (ir al norte).");
                break;
            case GOOSE_FOLLOWING: strcat(aux, "No has podido seleccionar oca (ir al oeste).");
                break;
            case GOOSE_PREVIOUS: strcat(aux, "No has podido seleccionar oca hacia atras (ir al este).");
                break;
            case TURNON: strcat(aux, "No has conseguido encender el objeto ");
		if(command_get_name(command)==NULL) return ERROR;
                strcat(aux, command_get_name(command));
                break;
            case TURNOFF: strcat(aux, "No has conseguido apagar el objeto ");
		if(command_get_name(command)==NULL) return ERROR;
                strcat(aux, command_get_name(command));
                break;
            case LOAD:
                strcat(aux, "No se ha cargado el juego guardado.");
                break;
            case SAVE:
                strcat(aux, "No se ha guardado el juego.");
                break;
            case OPEN:
                strcat(aux, "No has podido abrir ");
		if(command_get_name(command)==NULL) return ERROR;
                parte = strtok(command_get_name(command), " \n");
		if(parte==NULL) return ERROR;
                strcat(aux, parte);
                strcat(aux, " con ");
                parte = strtok(NULL, " \n");
                if (parte != NULL) {
                    strcat(aux, parte);
                }
                break;
            default: strcat(aux, "Comando no reconocido");
        }
    }
    return OK;
}
