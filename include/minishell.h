/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-alexandre.detoeuf
** File description:
** minishell.h
*/

/**
 * @file minishell.h
 * @brief Définitions et déclarations pour le projet de minishell.
 */

#ifndef MINISHELL_H
    #define MINISHELL_H

    #include <unistd.h>
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>

    /**
     * @brief Nombre maximal de commandes personnalisées.
     */
    #define NB_CUSTOM_COMMANDS 13

    /**
     * @brief Taille maximale d'une commande entrée.
     */
    #define COMMAND_INPUT_SIZE 1024

    /**
     * @brief Taille maximale d'un chemin.
     */
    #define MAX_PATH_SIZE 4096

    /**
     * @brief Alias pour réinitialiser la couleur du texte
     * à la couleur par défaut.
     */
    #define CNRM  "\x1B[0m"
    /**
     * @brief Alias pour définir la couleur du texte en rouge.
     */
    #define CRED  "\x1B[31m"
    /**
     * @brief Alias pour définir la couleur du texte en vert.
     */
    #define CGRN  "\x1B[32m"
    /**
     * @brief Alias pour définir la couleur du texte en jaune.
     */
    #define CYEL  "\x1B[33m"
    /**
     * @brief Alias pour définir la couleur du texte en bleu.
     */
    #define CBLU  "\x1B[34m"
    /**
     * @brief Alias pour définir la couleur du texte en magenta.
     */
    #define CMAG  "\x1B[35m"
    /**
     * @brief Alias pour définir la couleur du texte en cyan.
     */
    #define CCYN  "\x1B[36m"
    /**
     * @brief Alias pour définir la couleur du texte en blanc.
     */
    #define CWHT  "\x1B[37m"

/**
 * @brief Enumération pour les types de redirection.
 */
typedef enum redirection_type_e {
    E_WRITE, /**< Redirection en écriture. */
    E_APPEND, /**< Redirection en ajout. */
    E_READ, /**< Redirection en lecture. */
    E_READ_UNTIL, /**< Redirection en lecture jusqu'à. */
    E_NONE /**< Pas de redirection. */
} redirection_type_t;

/**
 * @brief Structure pour les redirections.
 */
typedef struct redirections_s {
    int fd; /**< Descripteur de fichier. */
    int redirect_index; /**< Index de redirection. */
    enum redirection_type_e type; /**< Type de redirection. */
} redirections_t;

/**
 * @brief Structure pour les alias.
 */
typedef struct aliases_s {
    char *alias; /**< Alias. */
    char *command; /**< Commande associée à l'alias. */
    struct aliases_s *next; /**< Alias suivant
 * dans la liste chaînée. */
} aliases_t;

/**
 * @brief Structure pour les variables locales.
 */
typedef struct local_var_s {
    char *name; /**< Nom de la variable. */
    char *value; /**< Valeur de la variable. */
    struct local_var_s *next; /**< Variable locale
 * suivante dans la liste chaînée. */
} local_var_t;

/**
 * @brief Enum pour les différentes types de processus dans
 * la liste chainée.
 */
typedef enum proc_type_s {
    BACKGROUNDED,
    FOREGROUNDED,
    AMPERSANDED
} proc_type_t;
/**
 * @brief Structure pour la gestion des processus.
 */
typedef struct process_list_s {
    pid_t pid; /**< ID du processus. */
    int id; /**< ID de la commande. */
    char *command; /**< Commande. */
    proc_type_t type; /**< Type du processus. */
    struct process_list_s *next; /**< Processus suivant
 * dans la liste chaînée. */
} process_list_t;

/**
 * @brief Structure pour la gestion des jobs.
 */
typedef struct job_manager_s {
    process_list_t *list; /**< Liste des processus. */
    int ampersand; /**< Indicateur d'esperluette. */
    int next_job_id; /**< ID du prochain job. */
} job_manager_t;

/**
 * @brief Structure principale pour
 * les informations sur l'état du shell.
 */
typedef struct info_s {
    int status; /**< Statut. */
    char *tmp_input; /**< Entrée temporaire. */
    char *input; /**< Entrée. */
    char **args; /**< Arguments. */
    char **env; /**< Variables d'environnement. */
    char *current_dir; /**< Répertoire actuel. */
    char *previous_dir; /**< Répertoire précédent. */
    char **command_list; /**< Liste de commandes. */
    redirections_t *redirections; /**< Redirections. */
    aliases_t *aliases; /**< Alias. */
    local_var_t *locale; /**< Variables locales. */
    job_manager_t *jobs; /**< Gestion des jobs. */
    char *home_var; /**< Variable HOME. */
    char *history_path; /**< Chemin de l'historique. */
    char *tmp_path; /**< Chemin temporaire. */
    int command_count; /**< Compteur de commandes. */
    int history_fd; /**< Descripteur de fichier de l'historique. */
} info_t;

/**
 * @brief Structure pour les informations sur les pipes.
 */
typedef struct pipe_info_s {
    pid_t pid; /**< ID du processus du pipe. */
    int fdb; /**< Descripteur de fichier du pipe. */
    char **commands; /**< Tableau de commandes. */
    int i; /**< Index. */
} pipe_info_t;

/**
 * @brief Tableau de pointeurs de fonctions
 * pour les commandes personnalisées.
 *
 * Ce tableau contient des pointeurs
 * de fonctions vers les commandes personnalisées
 * implémentées dans le minishell.
 */
extern int (* const custom_commands[NB_CUSTOM_COMMANDS]) (info_t *);

/**
 * @brief Tableau de chaînes de caractères
 * pour les préfixes des commandes personnalisées.
 *
 * Ce tableau contient les préfixes associés
 * à chaque commande personnalisée,
 * utilisés pour identifier et exécuter les
 * commandes appropriées.
 */
extern char const *custom_commands_prefix[NB_CUSTOM_COMMANDS];

/**
 * @brief Fonction qui renvoie la valeur d'une variable locale à partir de son
 * nom
 *
 * @param info Structure contenant les informations sur l'état du shell.
 */
char *get_local_variable(info_t *info, char *name);

/**
 * @brief Fonction pour remplacer les variables locales dans l'input de
 * l'utilisateur
 *
 * @param info Structure contenant les informations sur l'état du shell.
 */
void replace_local_variable(info_t *info);

/**
 * @brief Fonction pour effectuer une
 * vérification préalable à la gestion de la commande.
 *
 * Cette fonction effectue des vérifications
 * et des actions préalables avant de gérer la commande principale.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 */
void pre_handle_command_check(info_t *info);

/**
 * @brief Fonction pour gérer une commande.
 *
 * Cette fonction gère une commande saisie par l'utilisateur.
 *
 * @param info Structure contenant les
 * informations sur l'état du shell.
 * @return Le code de retour de la commande.
 */
int handle_command(info_t *info);

/**
 * @brief Fonction pour exécuter une commande.
 *
 * Cette fonction exécute une commande
 * spécifiée dans la structure d'information du shell.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @param is_local_command Indicateur de commande locale.
 * @return Le code de retour de la commande.
 */
int execute_command(info_t *info, int is_local_command);

/**
 * @brief Fonction pour vérifier si une commande est locale.
 *
 * Cette fonction vérifie si une commande
 * spécifiée est une commande locale.
 *
 * @param command Commande à vérifier.
 * @return 1 si la commande est locale, sinon 0.
 */
int is_local_command(char **command);

/**
 * @brief Fonction pour exécuter une commande locale.
 *
 * Cette fonction exécute une commande
 * locale spécifiée dans la structure d'information du shell.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @return Le code de retour de la commande.
 */
int execute_local_command(info_t *info);

/**
 * @brief Fonction pour détruire une liste d'alias.
 *
 * Cette fonction libère la mémoire utilisée par une liste d'alias.
 *
 * @param head Pointeur vers la tête de la liste d'alias.
 */
void destroy_aliases(aliases_t *head);

/**
 * @brief Fonction pour rechercher une commande d'alias.
 *
 * Cette fonction recherche une commande
 * associée à un alias dans la structure d'information du shell.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @return 1 si un alias est trouvé, sinon 0.
 */
int search_alias_command(info_t *info);

/**
 * @brief Fonction pour obtenir une commande d'alias.
 *
 * Cette fonction retourne la commande
 * associée à un alias spécifié dans la structure d'information du shell.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @param alias Alias pour lequel obtenir la commande.
 * @return La commande associée à l'alias ou
 * NULL si l'alias n'est pas trouvé.
 */
char *get_alias_command(info_t *info, char *alias);

/**
 * @brief Fonction pour détecter les alias dans une commande.
 *
 * Cette fonction détecte les alias
 * dans une commande donnée et les remplace par leurs commandes associées.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @return 1 si des alias sont détectés, sinon 0.
 */
int detecting_aliases(info_t *info);

/**
 * @brief Fonction pour remplacer les alias dans une commande.
 *
 * Cette fonction remplace les alias
 * présents dans une commande par leurs commandes associées.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 */
void replace_alias_in_command(info_t *info);

/**
 * @brief Fonction pour détruire une liste de variables locales.
 *
 * Cette fonction libère la mémoire
 * utilisée par une liste de variables locales.
 *
 * @param head Pointeur vers la tête de la liste de variables locales.
 */
void destroy_locales(local_var_t *head);


/**
 * @brief Fonction pour écrire une commande dans un fichier d'historique.
 *
 * Cette fonction écrit une commande dans un fichier d'historique.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 */
void write_command_to_file(info_t *info);

/**
 * @brief Fonction pour lire une entrée.
 *
 * Cette fonction lit une entrée saisie par l'utilisateur.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @param command Commande saisie par l'utilisateur.
 * @return Le code de retour de la lecture.
 */
int read_input(info_t *info, char *command);


/**
 * @brief Fonction pour gérer les redirections.
 *
 * Cette fonction gère les redirections pour une commande donnée.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @return Le code de retour de la gestion des redirections.
 */
int handle_redirections(info_t *info);

/**
 * @brief Fonction pour obtenir l'index de la redirection.
 *
 * Cette fonction obtient l'index de la redirection pour une commande donnée.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @return L'index de la redirection ou -1 en cas d'erreur.
 */
int get_redirection_index(info_t *info);

/**
 * @brief Fonction pour supprimer les arguments après une redirection.
 *
 * Cette fonction supprime les arguments
 * après une redirection dans la structure d'information du shell.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @param redirectIndex Index de la redirection.
 */
void delete_args_after_redirection(info_t *info, int redirectIndex);

/**
 * @brief Fonction pour ouvrir un fichier pour la redirection.
 *
 * Cette fonction ouvre un fichier pour
 * la redirection dans la structure d'information du shell.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @param filepath Chemin du fichier à ouvrir.
 * @return Le descripteur de fichier du fichier ouvert ou -1 en cas d'erreur.
 */
int open_file_for_redirect(info_t *info, char *filepath);

/**
 * @brief Fonction pour gérer les pipes.
 *
 * Cette fonction gère les pipes pour une commande donnée.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @return Le code de retour de la gestion des pipes.
 */
int handle_pipes(info_t *info);

/**
 * @brief Fonction pour exécuter des commandes avec des pipes.
 *
 * Cette fonction exécute des commandes avec
 * des pipes dans la structure d'information du shell.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @param commands Tableau de commandes.
 * @return Le code de retour de l'exécution des commandes avec des pipes.
 */
int execute_piped_commands(info_t *info, char **commands);

/**
 * @brief Fonction pour la logique des pipes.
 *
 * Cette fonction implémente la logique des pipes pour une commande donnée.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @param pinfo Informations sur les pipes.
 * @param fd Tableau de descripteurs de fichier.
 * @return Le code de retour de la logique des pipes.
 */
int pipe_logic(info_t *info, pipe_info_t *pinfo, int fd[2]);

/**
 * @brief Fonction pour parcourir les pipes.
 *
 * Cette fonction parcourt les pipes pour une série de commandes données.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @param commands Tableau de commandes.
 * @param pinfo Informations sur les pipes.
 * @param fd Tableau de descripteurs de fichier.
 * @return Le code de retour du parcours des pipes.
 */
int loop_through_pipes(info_t *info, char *const *commands,
    pipe_info_t *pinfo, int *fd);

/**
 * @brief Fonction pour gérer les globbings.
 *
 * Cette fonction gère les globbings pour une commande donnée.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @return Le code de retour de la gestion des globbings.
 */
int handle_globbings(info_t *info);

/**
 * @brief Fonction pour initialiser les signaux.
 *
 * Cette fonction initialise les
 * gestionnaires de signaux pour le shell.
 *
 * @param info Structure contenant
 * les informations sur l'état du shell.
 * @return Le code de retour de
 * l'initialisation des signaux.
 */
int init_signals(info_t *info);

/**
 * @brief Gestionnaire du signal SIGCHLD.
 *
 * Cette fonction est appelée
 * lorsqu'un processus enfant change d'état.
 *
 * @param sig Numéro du signal.
 */
void handle_sigchld(int sig);

/**
 * @brief Fonction pour afficher l'invite
 * de commande.
 *
 * Cette fonction affiche l'invite de
 * commande du shell.
 *
 * @param info Structure contenant les
 * informations sur l'état du shell.
 */
void display_input(info_t *info);

/**
 * @brief Fonction pour construire le chemin complet d'une commande.
 *
 * Cette fonction construit le chemin
 * complet d'une commande en recherchant dans les répertoires du PATH.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @param bin_path Chemin relatif de la commande.
 * @return Le chemin complet de la commande
 * ou NULL si la commande n'est pas trouvée.
 */
char *command_path_builder(info_t *info, char *bin_path);

/**
 * @brief Fonction pour activer le mode brut du terminal.
 *
 * Cette fonction active le mode brut du terminal pour la saisie.
 */
void enable_raw_mode(void);

/**
 * @brief Fonction pour désactiver le mode brut du terminal.
 *
 * Cette fonction désactive le mode brut du terminal.
 */
void disable_raw_mode(void);

/**
 * @brief Fonction pour gérer l'entrée dynamique.
 *
 * Cette fonction gère la saisie dynamique de l'utilisateur.
 *
 * @param position Position actuelle dans le buffer.
 * @param buffer Buffer contenant la saisie de l'utilisateur.
 * @param info Structure contenant les informations sur l'état du shell.
 */
void handle_input(int *position, char *buffer, info_t *info);

/**
 * @brief Fonction pour gérer l'entrée standard.
 *
 * Cette fonction gère l'entrée standard du shell en lisant et
 * en exécutant les commandes saisies par l'utilisateur.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @return Le code de retour de la gestion de l'entrée standard.
 */
int handle_stdin_input(info_t *info);

/**
 * @brief Fonction pour exécuter le shell.
 *
 * Cette fonction exécute le shell en gérant l'entrée standard et
 * en exécutant les commandes.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @return Le code de retour de l'exécution du shell.
 */
int execute_minishell(info_t *info);

/**
 * @brief Fonction pour exécuter les commandes.
 *
 * Cette fonction exécute les commandes saisies par l'utilisateur.
 *
 * @param info Structure contenant les informations sur l'état du shell.
 * @return Le code de retour de l'exécution des commandes.
 */
int run_commands(info_t *info);

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
 * @brief Affiche l'aide pour les commandes disponibles.
 *
 * Cette fonction affiche une liste des
 * commandes disponibles ainsi que leurs descriptions.
 * Elle est généralement utilisée lorsque
 * l'utilisateur demande de l'aide sans spécifier de commande particulière.
 */
void display_help_usage(void);

/**
 * @brief Affiche l'aide pour une commande spécifique
 * ou toutes les commandes disponibles.
 *
 * Cette fonction affiche une aide détaillée sur une
 * commande spécifique si un argument est fourni,
 * ou affiche une liste de toutes les commandes disponibles
 * avec leurs descriptions si aucun argument n'est fourni.
 *
 * @param info Pointeur vers la structure d'informations générales.
 * @return 0 si l'aide est affichée avec succès, -1 en cas d'erreur.
 */
int command_help(info_t *info);

#endif
