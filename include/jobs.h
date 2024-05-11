/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** jobs.h
*/

#ifndef JOBS_H
    #define JOBS_H
    #include "minishell.h"

/**
 * @brief Lance un processus en arrière-plan.
 *
 * @param info Pointeur vers la
 * structure d'informations générales.
 * @return 0 si le processus est lancé avec succès, -1 en cas d'erreur.
 */
int command_bg(info_t *info);

/**
 * @brief Détruit tous les jobs en cours.
 *
 * @param info Pointeur vers la structure d'informations générales.
 */
void destroy_jobs(info_t *info);

/**
 * @brief Recherche un processus par son nom.
 *
 * @param name Nom du processus à rechercher.
 * @param info Pointeur vers la
 * structure d'informations générales.
 * @return Pointeur vers la
 * structure du processus s'il est trouvé, NULL sinon.
 */
process_list_t *find_job_by_name(const char *name, info_t *info);

/**
 * @brief Recherche un processus par son identifiant.
 *
 * @param id Identifiant du processus à rechercher.
 * @param info Pointeur vers la structure
 * d'informations générales.
 * @return Pointeur vers la structure du
 * processus s'il est trouvé, NULL sinon.
 */
process_list_t *find_job_by_id(int id, info_t *info);

/**
 * @brief Fait passer un processus en premier plan.
 *
 * @param info Pointeur vers la structure
 * d'informations générales.
 * @return 0 si le processus est lancé en premier plan
 * avec succès, -1 en cas d'erreur.
 */
int command_fg(info_t *info);

/**
 * @brief Fonction pour détecter l'opérateur "&"
 * dans une ligne de commande.
 *
 * Cette fonction détecte la présence de l'opérateur
 * "&" dans une ligne de
 * commande et met à jour la structure d'informations
 * du shell en conséquence.
 *
 * @param info Structure contenant les informations
 * sur l'état du shell.
 * @param line Ligne de commande à analyser.
 */
void detect_ampersand(info_t *info, char *line);

/**
 * @brief Fonction pour ajouter une tâche à la liste
 * des jobs en arrière-plan.
 *
 * Cette fonction ajoute une tâche à la liste des
 * tâches en arrière-plan dans
 * la structure d'informations du shell.
 *
 * @param pid Identifiant du processus de la tâche.
 * @param command Commande exécutée par la tâche.
 * @param info Structure contenant les informations sur l'état du shell.
 * @param type Type du processus stocké.
 */
void add_job(pid_t pid, char *command, info_t *info, proc_type_t type);

#endif //JOBS_H
