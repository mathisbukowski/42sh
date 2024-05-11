/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** exit.h
*/

#ifndef EXIT_H
    #define EXIT_H
    #include "minishell.h"

/**
 * @brief Fonction pour quitter la commande "echo".
 *
 * Cette fonction quitte la commande "echo" avec un code de retour spécifié.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @param status Code de retour de la commande "echo".
 */
void exit_echo(info_t *info, int status);

/**
 * @brief Fonction pour quitter le programme fils.
 *
 * Cette fonction quitte le programme
 * fils avec un code de retour spécifié.
 *
 * @param info Structure contenant
 * les informations sur l'état du shell.
 * @param status Code de retour du programme fils.
 */
void exit_fork_program(info_t *info, int status);

/**
 * @brief Fonction pour quitter le processus principal.
 *
 * Cette fonction quitte le processus
 * principal dans la structure d'information du shell.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 */
void exit_main_process(info_t *info);

#endif //EXIT_H
