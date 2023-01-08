#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct USER joind_sb;
typedef struct POST post_sth;

struct POST
{
    char *user_name;
    char *post_text;
    int like;
    int post_id;
    int *num_like;
    post_sth *next;
};
struct USER
{
    char *user_name;
    char *pass_word;
    int user_id;
    struct USER *next;
};

void add_list(joind_sb **head, char *name, char *pass_word, int joined);
int search_for_user_name(joind_sb *head, char *name, char *user_name);
int search_password(joind_sb *head, char *pass_word);
int login(joind_sb *head, char *name, int post_id, post_sth **head_ps, int *like_ps);
int add_post(char *name, int post_id, char *post_text, joind_sb *head, int like, post_sth **head_ps);
int deleteNode(post_sth **head_ps, char *name, char *id);
int findUser(joind_sb *head, post_sth *head_ps, char *name);
int info(joind_sb *head, char *name, post_sth *head_ps);
void free_temp(char *arg1, char *arg2, char *command);
int checking_for_likes(post_sth *head, int like_ps, char *name);
void printing_post(post_sth *head_ps);
int already_have(joind_sb *head, char *name);
int number_of_posts(post_sth *head_ps, char *name);
void printing_people(joind_sb *head, post_sth *head_ps);
int likePosts(post_sth *head_ps, char *arg1, char *id, char *name, joind_sb *head);


int main()
{
    int marhale = 0;
    int quit = 0, number_of_join = 1;
    joind_sb *head = NULL;
    post_sth *head_ps = NULL;
    char dastor2[6] = {"login"}, dastor1[7] = {"signin"}, dastor3[] = {"exit"};
    printf("welcome to app\n");
    int like = 0, status = 0;
    int kkkk = 0, like_Ps = 1;
    int post_id = 1;
    while (quit != 50)
    {
        char *command = NULL, *name = NULL, *password = NULL;
        char c = 95;
        int flag = 0, count1 = 0, count2 = 0, count3 = 0, nextif = 0;
        int k = 1, m = 1, ll = 1;

        fflush(stdin);
        do
        {
            c = getchar();
            if (c == 32)
            {
                flag++;
            }
            if (flag == 0)
            {
                command = (char *)realloc(command, sizeof(char) * k);
                command[count1] = c;
                k++;
                count1++;
            }
            else if (flag == 1)
            {
                command[count1] = '\0';
                name = (char *)realloc(name, 8 * m);
                name[count2] = c;
                m++;
                count2++;
            }
            else if (flag == 2)
            {
                name[count2] = '\0';
                password = (char *)realloc(password, 8 * ll);
                password[count3] = c;
                ll++;
                count3++;
            }

        } while (c != '\n');
        if (strncmp(dastor3, command, 4) == 0)
        {
            name = NULL;
            password = NULL;
            printing_post(head_ps);
            printing_people(head, head_ps);
        }
        else if (password == NULL || name == NULL)
        {
            printf("wrong command!!\n");
            free(command);
            continue;
        }
        password[count3-1] = '\0';
        int check = 2;
        while (check != 0)
        {
            check = fflush(stdin);
        }
        if (strcmp(dastor1, command) == 0 && (name != NULL && password != NULL))
        {
            int check = 2;
            check = already_have(head, name);
            if (check == 0)
            {
                add_list(&head, name, password, number_of_join);
                printf("\tYour user name is :%s\n", name);
                printf("\tYour password is :%s\n", password);
                number_of_join++;
            }
            else
                printf("\tYou already joined\n");
        }
        else if (strcmp(dastor2, command) == 0)
        {
            fflush(stdin);
            if (search_for_user_name(head, name, password) == 0)
            {
                if (search_password(head, password) == 0)
                {
                    printf("\n\t Hi %s .lets see what your going to do\t\n", name);
                    login(head, name, post_id, &head_ps, &like_Ps);
                }
                else
                    printf("\n\t opps! wrong password\t\n");
            }
            else
                printf("\n\t make sure to signin first\t\n");
        }
        else
        {
            printf("\n\tthe entered command is not valid\t\n");
        }
        free(name);
        free(password);
    }
}
int search_for_user_name(joind_sb *head, char *name, char *user_name)
{
    joind_sb *pri;
    pri = head;
    while (pri != NULL)
    {
        if (strcmp(pri->user_name, name) == 0)
        {
            return 0;
        }

        pri = pri->next;
    }
    return 1;
}
int login(joind_sb *head, char *name, int post_id, post_sth **head_ps, int *like_ps)
{
    int like = 0, status = 0;
    int kkkk = 0;
    while (kkkk == 0)
    {
        char dastor1[] = {"post"}, dastor2[] = {"like"}, dastor3[] = {"logout"}, dastor4[] = {"delete"}, dastor5[] = {"info"}, dastor6[] = {"find_user"};
        char *command = (char *)malloc(sizeof(char));
        char *arg1 = (char *)malloc(sizeof(char));
        char *arg2 = (char *)malloc(sizeof(char));
        char c = 95;
        int flag = 0, count1 = 0, count2 = 0, count3 = 0, nextif = 0;
        int k = 1, m = 1, ll = 1;
        fflush(stdin);
        do
        {
            c = getchar();
            if (c == 32)
            {
                flag++;
            }
            if (flag == 0)
            {
                command = (char *)realloc(command, 8 * (k));
                command[count1] = c;
                k++;
                count1++;
            }
            else if (flag == 1)
            {
                arg1 = (char *)realloc(arg1, 8 * (m));
                arg1[count2] = c;
                m++;
                count2++;
            }
            else
            {
                arg2 = (char *)realloc(arg2, 8 * (ll));
                arg2[count3] = c;
                ll++;
                count3++;
            }

        } while (c != '\n');
        command[count1] = '\0';
        for (int i = 0; i < 15; i++)
        {
            fflush(stdin);
        }
        if (strncmp(dastor3, command, 6) == 0)
        {
            arg1 = NULL;
            arg2 = NULL;
        }
        else if (strncmp(dastor5, command, 4) == 0)
        {
            arg1 = NULL;
            arg2 = NULL;
        }
        else if (strcmp(dastor4, command) == 0)
        {
            arg1[count2] = '\0';
            arg2 = NULL;
        }
        else if (strcmp(dastor6, command) == 0)
        {
            arg1[count2 - 1] = '\0';
            arg2 = NULL;
        }
        else
        {
            arg1[count2] = '\0';
            arg2[count3-1] = '\0';
        }

        if (strcmp(dastor1, command) == 0)
        {
            strcat(arg1, arg2);
            //printf("\tname:%s\n", arg1);
            status = add_post(name, post_id, arg1, head, like, &(*head_ps));
            if (status == 0)
            {
                printf("\n\t your post was made successfully !!\t\n");
            }
            else
                printf("\n\t somthing must went wrong.try again!\t\n");
            post_id++;
            continue;
        }
        else if (strcmp(dastor2, command) == 0)
        {
            free(command);
            status = likePosts((*head_ps), arg1, arg2, name, head);
            if (status == 0)
            {
                printf("\n\tyou like the post\t\n");
                (*like_ps)++;
            }
            else
                printf("\n\ttry again!\t\n");
        }
        else if (strncmp(dastor3, command, 6) == 0)
        {
            free(command);
            printf("\n\t we hope to see you again %s :))\t\n",name);
            break;
        }
        else if (strcmp(dastor4, command) == 0)
        {
            free(command);
            status = deleteNode(&(*head_ps), name, arg1);
            if (status == 0)
            {
                printf("\n\t the process completed\t\n");
            }
            else
                printf("\n\t the post dosent exist or has already been removed\n");
            // free(arg1);
            // free(arg2);
        }
        else if (strncmp(dastor5, command, 4) == 0)
        {

            status = info(head, name, (*head_ps));
            if (status == 0)
            {
                printf("\n\t this is your record\t\n");
            }
            else
                printf("\n\t argumants dont match expectants \t\n");
        }
        else if (strcmp(dastor6, command) == 0)
        {
            free(command);

            status = findUser(head, (*head_ps), arg1);
            if (status == 0)
            {
                printf("\n\t the information is written above\t\n");
            }
            else
                printf("\n\t argumants dont match expectants \t\n");
            // free(arg1);
            // free(arg2);
        }
        else
        {
            free(command);
            printf("\n\t you must enter the command correctly!!\n");
            // free(arg1);
            // free(arg2);
        }
        free(arg1);
        free(arg2);
    }
    return 0;
}
void add_list(joind_sb **head, char *name, char *pass_word, int joined)
{
    int n = 0, p = 0;
    joind_sb *new_node;
    joind_sb *last = *head;
    new_node = (joind_sb *)malloc(sizeof(joind_sb));
    n = strlen(name);
    new_node->user_name = (char *)malloc(sizeof(char) * (n + 1));
    strcpy(new_node->user_name, name);
    p = strlen(pass_word);
    new_node->pass_word = (char *)malloc(sizeof(char) * (p + 1));
    strcpy(new_node->pass_word, pass_word);
    new_node->user_id = joined;
    new_node->next = NULL;
    if (*head == NULL)
    {

        *head = new_node;
    }
    else
    {
        while (last->next != NULL)
            last = last->next;
        last->next = new_node;
    }
}

int search_password(joind_sb *head, char *pass_word)
{
    joind_sb *pri;
    pri = head;
    while (pri != NULL)
    {
        if (strcmp(pri->pass_word, pass_word) == 0)
        {
            return 0;
        }
        pri = pri->next;
    }
    return 1;
}
int add_post(char *name, int post_id, char *post_text, joind_sb *head, int like, post_sth **head_ps)
{
    post_sth *newNode, *last = *head_ps;
    newNode = (post_sth *)malloc(sizeof(post_sth));
    // printf("\tname:%s\n", post_text);

    int length = strlen(post_text);
    newNode->post_text = (char *)malloc(sizeof(char) * (length + 1));
    strcpy(newNode->post_text, post_text);

    newNode->post_id = post_id;

    length = strlen(name);
    newNode->user_name = (char *)malloc(sizeof(char) * (length + 1));
    strcpy(newNode->user_name, name);
    newNode->num_like = (int *)malloc(sizeof(int));
    newNode->like = 0;
    // printf("\njjj\n");
    newNode->next = NULL;
    // printf("\njjj\n");
    if (*head_ps == NULL)
    {
        *head_ps = newNode;
    }
    else
    {
        while (last->next != NULL)
            last = last->next;
        last->next = newNode;
    }
    return 0;
}

int deleteNode(post_sth **head_ps, char *name, char *id)
{
    int post_id;
    post_id = atoi(id);
    post_sth *temp;
    if (strcmp((*head_ps)->user_name, name) == 0 && ((*head_ps)->post_id == post_id))
    {
        temp = *head_ps; // backup to free the memory
        *head_ps = (*head_ps)->next;
        free(temp);
        return 0;
    }
    else
    {
        post_sth *current = *head_ps;
        while (current->next != NULL)
        {
            if (current->next->post_id == post_id && strcmp(current->next->user_name, name) == 0)
            {
                temp = current->next;
                current->next = current->next->next;
                free(temp);
                return 0;
                break;
            }
            else
                current = current->next;
        }
    }
    return 1;
}
int findUser(joind_sb *head, post_sth *head_ps, char *name)
{
    int found = 0;
    while (head != NULL)
    {
        if (strcmp(head->user_name, name) == 0)
        {
            printf("\n\tUSER_ID: - %s -\t\n", head->user_name);
            printf("---------------------------------\n");
            found++;
        }
        head = head->next;
    }
    if (found == 1)
    {
        while (head_ps != NULL)
        {
            if (strcmp(head_ps->user_name, name) == 0)
            {
                printf("\tUser name : - %s -\n", head_ps->user_name);
                printf("\tpost_id : -%d -\n", head_ps->post_id);
                printf("\tPOST: - %s-\n ", head_ps->post_text);
                printf("\tlike: -%d-\n", head_ps->like);
                printf("---------------------------------\n");

            }
            head_ps = head_ps->next;
        }
        return 0;
    }
    else

        return 1;
}
int info(joind_sb *head, char *name, post_sth *head_ps)
{
    while (head != NULL)
    {
        if (strcmp(head->user_name, name) == 0)
        {
            printf("\n\tThe user: - %s - with password: - %s\n", head->user_name, head->pass_word);
            printf("\t---------------------------------\n");
        }
        head = head->next;
    }
    while (head_ps != NULL)
    {
        if (strcmp(head_ps->user_name, name) == 0)
        {
            printf("\tPOST-ID : - %d -\n", head_ps->post_id);
            printf("\tLIKE: - %d -\n", head_ps->like);
            printf("\tPOST: - %s \n", head_ps->post_text);
            printf("\t---------------------------------\n");
        }
        head_ps = head_ps->next;
    }
    return 0;
}
int already_have(joind_sb *head, char *name)
{
    joind_sb *pri;
    pri = head;
    while (pri != NULL)
    {
        if (strcmp(pri->user_name, name) == 0)
        {
            return 1;
        }

        pri = pri->next;
    }
    return 0;
}
int likePosts(post_sth *head_ps, char *arg1, char *id, char *name, joind_sb *head)
{
    int whereToAdd = 0;
    int TheOneLiked = 0;
    int tedad_like = 0;
    int PostId = atoi(id);
    while (head != NULL)
    {
        if (strcmp(head->user_name, name) == 0)
        {
            TheOneLiked = head->user_id;
        }
        head = head->next;
    }
    while (head_ps != NULL)
    {
        if (strcmp((head_ps)->user_name, arg1) == 0)
        {
            if ((head_ps)->post_id == PostId)
            {
                tedad_like = (head_ps)->like;
                if (tedad_like > 0)
                {
                    for (int i = 0; i < tedad_like; i++)
                    {
                        if ((head_ps)->num_like[i] == TheOneLiked)
                        {
                            printf("\nalready like it\n");
                            return 1;
                            break;
                        }
                    }
                    (head_ps)->like++;
                    (head_ps)->num_like = (int *)realloc((head_ps)->num_like, sizeof(int) * (tedad_like + 1));
                    (head_ps)->num_like[tedad_like] = TheOneLiked;
                    return 0;
                }
                else
                {
                    (head_ps)->like++;
                    (head_ps)->num_like = (int *)realloc((head_ps)->num_like, sizeof(int) * (tedad_like + 1));
                    (head_ps)->num_like[tedad_like] = TheOneLiked;
                    return 0;
                }
            }
        }
        head_ps = (head_ps)->next;
    }
    return 1;
}

int number_of_posts(post_sth *head_ps, char *name)
{
    int num = 0;
    while (head_ps != NULL)
    {
        if (strcmp(head_ps->user_name, name) == 0)
        {
            num++;
        }
        head_ps = head_ps->next;
    }
    return num;
}
void printing_people(joind_sb *head, post_sth *head_ps)
{
    FILE *accounts;
    accounts = fopen("accounts.txt", "w");
    int num = 0;

    while (head != NULL)
    {
        fprintf(accounts, " %s ", head->user_name, "\n");
        fprintf(accounts, " %s ", head->pass_word);
        //fprintf(accounts, "ID NUMBER OF USER : %d\n", head->user_id);
        int num = number_of_posts(head_ps, head->user_name);
        fprintf(accounts, " %d \n", num);
        //fprintf(accounts, "------------------------------\n");
        head = head->next;
    }
    fclose(accounts);
}

void printing_post(post_sth *head_ps)
{
    FILE *posts;
    posts = fopen("post.txt", "w");
    while (head_ps != NULL)
    {
        fprintf(posts, " %s ", head_ps->post_text);
        fprintf(posts, " %s ", head_ps->user_name);
        fprintf(posts, " %d\n ", head_ps->like);
        //fprintf(posts, "POST ID : %d\n ", head_ps->post_id);
       // fprintf(posts, "------------------------------\n");
        head_ps = head_ps->next;
    }
    fclose(posts);
}
