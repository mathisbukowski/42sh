/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** utils.h
*/

#ifndef UTILS_H
    #define UTILS_H
    #include "minishell.h"
/**
 * @brief Fonction pour formater un répertoire.
 *
 * Cette fonction formate un répertoire pour l'affichage en
 * remplaçant le chemin complet par "~" s'il correspond au
 * répertoire personnel de l'utilisateur.
 *
 * @param info Structure contenant les
 * informations sur l'état du shell.
 * @param dir Répertoire à formater.
 * @return Le répertoire formaté.
 */
char *format_dir(info_t *info, char *dir);

/**
 * @brief Fonction pour initialiser une
 * structure de redirections.
 *
 * Cette fonction initialise une structure de redirections
 * avec des valeurs par défaut.
 *
 * @return Un pointeur vers la structure
 * de redirections initialisée.
 */
redirections_t *init_redirection(void);

/**
 * @brief Fonction pour initialiser une structure de
 * gestionnaire de tâches.
 *
 * Cette fonction initialise une structure
 * de gestionnaire
 * de tâches avec des valeurs par défaut.
 *
 * @return Un pointeur vers la structure
 * de gestionnaire
 * de tâches initialisée.
 */
job_manager_t *init_jobs(void);

/**
 * @brief Fonction pour initialiser les champs
 * de la structure
 * d'informations du shell.
 *
 * Cette fonction initialise les champs de la structure
 * d'informations du shell avec des valeurs par défaut.
 *
 * @param info Structure contenant les informations
 * sur l'état du shell.
 * @return Le code de retour de l'initialisation
 * des champs.
 */
int init_info_fields(info_t *info);

/**
 * @brief Fonction pour libérer la mémoire allouée
 * lors de l'initialisation du shell.
 *
 * Cette fonction libère la mémoire allouée lors
 * de l'initialisation du shell.
 *
 * @param info Structure contenant les informations
 * sur l'état du shell.
 */
void free_init(info_t *info);

/**
 * @brief Fonction pour gérer
 * les opérateurs logiques
 *
 * Cette fonction gère && et ||
 *
 * @param info Structure contenant les informations sur l'état du shell.
 */
int handle_double_pipe_and(info_t *info);

/**
 * @brief Fonction pour initialiser la structure d'informations du shell.
 *
 * Cette fonction initialise la structure d'informations du
 * shell avec les variables d'environnement fournies.
 *
 * @param env Tableau de chaînes de caractères représentant
 * les variables d'environnement.
 * @return Un pointeur vers la structure d'informations initialisée.
 */
info_t *init_info(char **env);

/**
 * @brief Fonction pour obtenir le chemin complet d'un fichier.
 *
 * Cette fonction retourne le chemin complet d'un fichier à partir d'un
 * sous-répertoire et d'un nom de fichier spécifiés.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @param subdir Sous-répertoire.
 * @param filename Nom de fichier.
 * @return Le chemin complet du fichier.
 */
char *get_full_path(info_t *info, const char *subdir, const char *filename);

/**
 * @brief Fonction pour afficher une erreur de commande non trouvée.
 *
 * Cette fonction affiche un message d'erreur indiquant
 * que la commande spécifiée n'a pas été trouvée.
 *
 * @param command Nom de la commande non trouvée.
 */
void print_command_not_found_error(char *command);

/**
 * @brief Fonction pour afficher une erreur avec le code d'erreur errno.
 *
 * Cette fonction affiche un message d'erreur avec
 * le préfixe spécifié et le code d'erreur errno.
 *
 * @param prefix Préfixe de l'erreur.
 */
void print_error_errno(char *prefix);

/**
 * @brief Fonction pour afficher une erreur avec un message personnalisé.
 *
 * Cette fonction affiche un message d'erreur avec un
 * préfixe et un message personnalisé spécifiés.
 *
 * @param prefix Préfixe de l'erreur.
 * @param msg Message d'erreur personnalisé.
 */
void print_error(char *prefix, char *msg);

/**
 * @brief Fonction pour afficher un message d'erreur.
 *
 * Cette fonction affiche un message d'erreur spécifié.
 *
 * @param msg Message d'erreur à afficher.
 */
void print_error_message(char *msg);

/**
 * @brief Fonction pour ajouter une lettre à une chaîne de caractères.
 *
 * Cette fonction ajoute une lettre à une chaîne de caractères spécifiée.
 *
 * @param cleaned_str Chaîne de caractères nettoyée.
 * @param c Lettre à ajouter.
 * @param has_word Indicateur indiquant si un mot est en cours.
 * @param is_word_after Indicateur indiquant si un mot est après.
 */
void add_letter(char *cleaned_str, char c, int *has_word, int is_word_after);

/**
 * @brief Fonction pour ajouter un caractère à une chaîne de caractères.
 *
 * Cette fonction ajoute un caractère
 * à une chaîne de caractères spécifiée.
 *
 * @param str Chaîne de caractères.
 * @param c Caractère à ajouter.
 */
void append(char *str, char c);

/**
 * @brief Fonction pour vérifier s'il y a un mot
 * après un index donné dans une chaîne de caractères.
 *
 * Cette fonction vérifie s'il y a un mot après
 * un index donné dans une chaîne de caractères spécifiée.
 *
 * @param str Chaîne de caractères.
 * @param index Index donné.
 * @return 1 s'il y a un mot après l'index, sinon 0.
 */
int is_there_word_after(char *str, int index);

/**
 * @brief Fonction pour obtenir la branche git d'un répertoire.
 *
 * Cette fonction retourne
 * le nom de la branche git d'un répertoire spécifié.
 *
 * @param dir Répertoire pour lequel obtenir la branche git.
 * @return Le nom de la branche git
 * ou NULL si le répertoire n'est pas un dépôt git.
 */
char *get_dir_git_branch(char *dir);

/**
 * @brief Fonction pour vérifier si un répertoire est un dépôt git.
 *
 * Cette fonction vérifie si un
 * répertoire spécifié est un dépôt git.
 *
 * @param dir Répertoire à vérifier.
 * @return Le chemin du répertoire git
 * ou NULL si le répertoire n'est pas un dépôt git.
 */
char *check_if_git_dir_exist(char *dir);

/**
 * @brief Fonction pour obtenir le répertoire source git.
 *
 * Cette fonction retourne le répertoire
 * source git à partir d'un répertoire de base spécifié.
 *
 * @param base_dir Répertoire de base.
 * @return Le répertoire source git ou
 * NULL si le répertoire source git n'est pas trouvé.
 */
char *get_git_src_dir(char *base_dir);

/**
 * @brief Fonction pour obtenir le nom de la
 * branche git à partir d'un fichier.
 *
 * Cette fonction retourne le nom de la branche
 * git à partir d'un fichier spécifié.
 *
 * @param file_path Chemin du fichier.
 * @return Le nom de la branche git ou NULL si le fichier n'est pas trouvé.
 */
char *get_branch_name_from_file(char *file_path);

/**
 * @brief Fonction pour initialiser le répertoire courant.
 *
 * Cette fonction initialise le répertoire courant du shell.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @return Le code de retour de l'initialisation du répertoire courant.
 */
int init_current_dir(info_t *info);

/**
 * @brief Fonction pour mettre à jour le répertoire courant.
 *
 * Cette fonction met à jour le
 * répertoire courant du shell.
 *
 * @param info Structure contenant
 * les informations sur l'état du shell.
 * @return Le code de retour de la mise à jour du répertoire courant.
 */
int update_current_dir(info_t *info);

/**
 * @brief Fonction pour nettoyer une chaîne de caractères.
 *
 * Cette fonction nettoie une chaîne de
 * caractères en supprimant les caractères de fin de ligne.
 *
 * @param str Chaîne de caractères à nettoyer.
 * @return La chaîne de caractères nettoyée.
 */
char *clean_str(char *str);

/**
 * @brief Fonction pour libérer la mémoire allouée pour les chemins.
 *
 * Cette fonction libère la mémoire allouée pour les chemins.
 *
 * @param paths Tableau de chaînes de
 * caractères représentant les chemins.
 * @param path Chaîne de caractères représentant un chemin.
 * @param env_path Chaîne de caractères
 * représentant un chemin dans les variables d'environnement.
 */
void free_path(char **paths, char *path, char *env_path);

#endif //UTILS_H
