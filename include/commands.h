/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** aliases.h
*/

#ifndef COMMANDS_H
    #define COMMANDS_H
    #include "minishell.h"

/**
 * @brief Fonction pour exécuter la commande "alias".
 *
 * Cette fonction exécute la commande
 * "alias" pour définir un alias.
 *
 * @param info Structure contenant
 * les informations sur l'état du shell.
 * @return Le code de retour de la commande "alias".
 */
int command_alias(info_t *info);

/**
 * @brief Fonction pour exécuter la commande "unalias".
 *
 * Cette fonction exécute la commande
 * "unalias" pour supprimer un alias.
 *
 * @param info Structure contenant
 * les informations sur l'état du shell.
 * @return Le code de retour de la commande "unalias".
 */
int command_unalias(info_t *info);

/**
 * @brief Fonction pour exécuter la commande "cd".
 *
 * Cette fonction exécute la commande
 * "cd" pour changer de répertoire.
 *
 * @param info Structure contenant
 * les informations sur l'état du shell.
 * @return Le code de retour de la commande "cd".
 */
int command_cd(info_t *info);

/**
 * @brief Fonction pour exécuter la commande "env".
 *
 * Cette fonction exécute la commande
 * "env" pour afficher les variables d'environnement.
 *
 * @param info Structure contenant
 * les informations sur l'état du shell.
 * @return Le code de retour de la commande "env".
 */
int command_env(info_t *info);

/**
 * @brief Fonction pour exécuter la commande "setenv".
 *
 * Cette fonction exécute la commande
 * "setenv" pour définir une variable d'environnement.
 *
 * @param info Structure contenant
 * les informations sur l'état du shell.
 * @return Le code de retour de la commande "setenv".
 */
int command_setenv(info_t *info);

/**
 * @brief Fonction pour exécuter la commande "unsetenv".
 *
 * Cette fonction exécute la commande
 * "unsetenv" pour supprimer une variable d'environnement.
 *
 * @param info Structure contenant
 * les informations sur l'état du shell.
 * @return Le code de retour de la commande "unsetenv".
 */
int command_unsetenv(info_t *info);

/**
 * @brief Fonction pour afficher l'historique des commandes.
 *
 * Cette fonction affiche l'historique
 * des commandes saisies par l'utilisateur.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @return Le code de retour de l'affichage de l'historique.
 */
int command_history(info_t *info);

/**
 * @brief Fonction pour exécuter la commande "set".
 *
 * Cette fonction exécute la commande
 * "set" pour afficher les variables locales.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @return Le code de retour de la commande.
 */
int command_set(info_t *info);

/**
 * @brief Fonction pour exécuter la commande "unset".
 *
 * Cette fonction exécute la commande
 * "unset" pour supprimer une variable locale.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @return Le code de retour de la commande.
 */
int command_unset(info_t *info);

#endif //COMMANDS_H
