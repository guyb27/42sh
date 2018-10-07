| <h1 background-color: black>42SH</h1> |
| :-----------:|
| <h2>Description</h2> |
| Ce projet consiste à créer de toutes pièces un shell complet, en reprenant le travail effectué sur votre 21sh. Un jeu minimum de fonctionnalités vous sont demandées, à partir duquel vous allez constuire votre propre shell abouti - en allant potentiellement jusqu'au job control et au shell script. Ce projet vous permet donc de voir ou revoir une très large palette des fonctionnalités UNIX (et POSIX) standard. |

| <h2>Partie Obligatoire</h2> | <h2>status</h2> |
| :-----------: | :-----------:|
| NORME. | 🐌 |
| LEAKS. | 🐌 |
| Affichage d’un prompt. | ✅ |
| lecture de la ligne de commande, sans édition de ligne. | ✅ |
| Exécution de commandes simples avec leurs paramètres et gestion du PATH. | ✅ |
| Les opérateurs de redirection suivants : ">", ">>", "<". | ✅ |
| Les opérateurs logiques "&&" et "\|\|". | ✅ |
| Le séparateur ";" | ✅ |
| Gestion correcte des espaces et des tabulations. | ✅ |
| Gestion des erreurs et de la valeur de retour des commandes | ✅ |
| echo | ✅ |
| cd | ❌ |
| exit | ❌ |
| env | ✅ |
| setenv | ✅ |
| unsetenv | ✅ |
| GESTION DE LA VARIABLE PATH | ❌ |
| Les pipes "\|" | ✅ |
| Les aggrégations de descripteurs de fichiers, par exemple pour fermer la sortie d’erreur | ✅ |
| Editer la ligne à l’endroit où se trouve le curseur. | ✅ |
| Déplacer le curseur vers la gauche et vers la droite pour pouvoir éditer la ligne à un endroit précis. Les nouveaux caractères doivent bien entendu s’insérer entre les caractères existants de la même manière que dans un shell ordinaire.| ✅ |
| Utiliser les fleches du haut et du bas pour naviguer dans l’historique des commandes que l’on pourra alors éditer si le coeur nous en dit (la ligne, pas l’historique, hein).| ✅ |
| Couper, copier et/ou coller tout ou partie d’une ligne avec la séquence de touches qui vous plaira.| ✅ |
| Se déplacer par "mot" vers la gauche et vers la droite avec ctrl+LEFT et ctrl+RIGHT ou toute autre combinaison de touche raisonnable.| ✅ |
| Aller directement au début et à la fin d’une ligne avec home et end. | ✅ |
| Ecrire ET éditer une commande sur plusieurs lignes. Dans ce cas, on apprecierait que ctrl+UP et ctrl+DOWN permettent de passer d’une ligne à l’autre de la commande en restant sur la même colonne ou la colonne la plus appropriée sinon.| ✅ |
| Gérer complètement les quotes et doubles quotes, même sur plusieurs lignes (hors expansions).| ✅ |


| <h2>Partie Bonus</h2> | <h2>status</h2> |
| :-----------: | :-----------:|
| Les inhibiteurs """ (double quote), "’" (simple quote) et "\" (backslash). | ✅ |
| Les redirections avancées : l’aggrégation des sorties de fichier et le heredoc "<<". | ✅ |
| Edition de ligne telle que demandée dans le ftsh3. | ✅ |
| les variables locales et les builtin unset et export. | ✅ |
| Les back quotes "‘". | ✅ |
| L’historique des commandes et les builtins history et "!" avec toutes leurs options si elles en ont. | 🐢 |
| Complétion dynamique. | 🐢 |
| Le globing : "\*", "?", "[]", "{}", etc. (sans utiliser la fonction glob(3) !) | ❌ |
| Le Job control et les builtins jobs, fg et bg, et l’operateur "&". | 🐌 |
| Rechercher dans l’historique avec ctrl+R. | ❌ |
| COLORISATION SYNTAXIQUE DU SHELL ACTIVABLE ET DESACTIVABLE | ❌ |
| COMPLETION COMME LE THEME FISH | ❌ |

PROBLEMES A RESOUDRE:<br/>
\_cd ..<br/>
\_LA FONCTION CD NE FONCTIONNE PAS<br/>
\_TABLE DE HASH<br/>
\_Les retours d'erreurs<br/>
\_GESTION DU CTRL+D APRES UNE/DES ERREURS
\_PASSER LA LIGNE EN TEMPORAIRE TANT QU UNE AUTRE TOUCHE IMPRIMABLE N A PAS ETAIT SAISIE(HISTORIQUE)<br/>
\_PROBLEME DE RETOUR DE PIPE DANS EDITOR, PAR EXEMPLE:<br/>
echo |<br/>
\_PROBLEME FLECHE DU BAS<br>
\_LORSQUE L'ON FAIT UNE COMMANDE QUI N EXISTE PAS ET ENSUITE CTRL+C ON PERD LE CHEMAIN DU HOME DANS LE PROMPT<br/>
\_echo | [ENTER] + <cat>

EDITION DE LIGNE:<br/>
\_QUAND IL Y A UNE COMMANDE SUR PLUSIEUR LIGNE ET QUE L ON FAIT FLECHE DE GAUCHE<br/>

SEGFAULT A RESOUDRE:<br/>
\_ENVIRONNEMENT VIDE<br/>
\_Petit segfault de temps en temps dans add\_char<br/>

HISTORIQUE:<br/>
\_IL FAUT APPUYER DEUX FOIS SUR LA FLECHE DU BAS A LA FIN POUR RECUPERER LA LIGNE<br/>
\_DECONNE DE TEMPS EN TEMPS<br/>
\_VA UN CARACTERE TROP LOIN ET COMMENCE UN CARACTERE TROP LOIN<br/>

TABULATION:<br/>
\_SI L ELEMENT EST PLUS GRAND QUE WS\_COL, REGLE SALEMENT<br/>
\_LE REFRESH<br/>
\_POUR FAIRE PROPRE IL FAUX DEL LES LINE EN TROP QUAND LE PROMPT PASSE DE +1/-1 LIGNE ET REINTRODUIRE LE PROMPT ENTRE LES DEUX MAIS POUR L INSTANT ON SE CONTENTE DE CA !

FONCTION READ:<br/>
LA TOUCHE BACKSPACE FONCTIONNE D UNE MANIERE ETRANGE<br/>
