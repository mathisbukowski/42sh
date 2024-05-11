/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** env.h
*/

#ifndef ENV_H
    #define ENV_H
    #include "minishell.h"

/**
 * @brief Fonction pour initialiser les variables
 * d'environnement.
 *
 * Cette fonction initialise les variables
 * d'environnement du shell.
 *
 * @param info Structure contenant les informations
 * sur l'état du shell.
 * @param env Tableau de chaînes de caractères
 * représentant les variables d'environnement.
 * @return Le code de retour de l'initialisation
 * des variables d'environnement.
 */
int init_env(info_t *info, char **env);

/**
 * @brief Fonction pour copier un tableau de
 * chaînes de caractères représentant les variables d'environnement.
 *
 * Cette fonction copie un tableau de chaînes
 * de caractères représentant les variables d'environnement.
 *
 * @param env Tableau de chaînes de caractères
 * représentant les variables d'environnement à copier.
 * @return Le tableau de chaînes de caractères copié.
 */
char **copy_env(char **env);

/**
 * @brief Fonction pour obtenir la valeur
 * d'une variable d'environnement.
 *
 * Cette fonction retourne la valeur
 * d'une variable d'environnement spécifiée.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @param key Clé de la variable d'environnement
 * dont on veut obtenir la valeur.
 * @return La valeur de la variable
 * d'environnement ou NULL si la clé n'est pas trouvée.
 */
char *get_env_value(info_t *info, char *key);
#endif //ENV_H
