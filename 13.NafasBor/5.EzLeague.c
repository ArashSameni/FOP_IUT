#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 2000
#define PLAYERSCOUNT 500

typedef struct _player
{
    int id;
    int teamId;
    char name[SIZE];
    int price;
    int speed;
    int finishing;
    int defence;
} player;

typedef struct _team
{
    int id;
    char name[SIZE];
    int money;
    int players[PLAYERSCOUNT];
    int playersCount;
    int wins;
    int loses;
    int eqs;
} team;

void swapStrings(char* str1, char* str2){
    char str[SIZE];
    strcpy(str, str1);
    strcpy(str1, str2);
    strcpy(str2, str);
}

int main()
{
    char cmd[SIZE] = {};
    int countOfPlayers = 0;
    int countOfTeams = 0;
    player *players = (player *)malloc(sizeof(player) * (countOfPlayers + 1));
    team *teams = (team *)malloc(sizeof(team) * (countOfTeams + 1));
    do
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "new") == 0)
        {
            char type[7];
            scanf("%s", type);
            if (strcmp(type, "player") == 0)
            {
                char name[SIZE];
                scanf("%s", name);
                int price, speed, finishing, defence;
                scanf("%d %d %d %d", &price, &speed, &finishing, &defence);
                players = realloc(players, sizeof(player) * (countOfPlayers + 1));
                players[countOfPlayers].id = countOfPlayers + 1;
                players[countOfPlayers].teamId = -1;
                strcpy(players[countOfPlayers].name, name);
                players[countOfPlayers].price = price;
                players[countOfPlayers].speed = speed;
                players[countOfPlayers].finishing = finishing;
                players[countOfPlayers].defence = defence;
                countOfPlayers++;
            }
            else if (strcmp(type, "team") == 0)
            {
                char name[SIZE];
                scanf("%s", name);
                bool teamExists = false;
                for (int i = 0; i < countOfTeams; i++)
                    if (strcmp(name, teams[i].name) == 0)
                    {
                        teamExists = true;
                        break;
                    }
                int money;
                scanf("%d", &money);
                if (!teamExists)
                {
                    teams = realloc(teams, sizeof(team) * (countOfTeams + 1));
                    teams[countOfTeams].id = countOfTeams + 1;
                    strcpy(teams[countOfTeams].name, name);
                    teams[countOfTeams].money = money;
                    teams[countOfTeams].playersCount = 0;
                    for (int i = 0; i < PLAYERSCOUNT; i++)
                        teams[countOfTeams].players[i] = -1;
                    teams[countOfTeams].wins = 0;
                    teams[countOfTeams].loses = 0;
                    teams[countOfTeams].eqs = 0;
                    countOfTeams++;
                }
            }
        }
        else if (strcmp(cmd, "buy") == 0)
        {
            int playerId, teamId;
            scanf("%d %d", &playerId, &teamId);
            if (playerId > countOfPlayers || playerId < 1)
                printf("player with the id %d doesnt exist\n", playerId);
            else if (teamId > countOfTeams || teamId < 1)
                printf("team with the id %d doesnt exist\n", teamId);
            else if (players[playerId - 1].price > teams[teamId - 1].money)
                printf("the team cant afford to buy this player\n");
            else if (players[playerId - 1].teamId != -1)
                printf("player already has a team\n");
            else
            {
                players[playerId - 1].teamId = teamId;
                int count = teams[teamId - 1].playersCount++;
                teams[teamId - 1].players[count] = playerId;
                teams[teamId - 1].money -= players[playerId - 1].price;
                printf("player added to the team succesfully\n");
            }
        }
        else if (strcmp(cmd, "sell") == 0)
        {
            int playerId, teamId;
            scanf("%d %d", &playerId, &teamId);
            if (teamId > countOfTeams || teamId < 1)
                printf("team doesnt exist\n");
            else if (players[playerId - 1].teamId != teamId)
                printf("team doesnt have this player\n");
            else
            {
                players[playerId - 1].teamId = -1;
                int count = teams[teamId - 1].playersCount--;
                for (int i = 0; i < PLAYERSCOUNT; i++)
                {
                    if (teams[teamId - 1].players[i] == playerId)
                    {
                        teams[teamId - 1].players[i] = -1;
                        break;
                    }
                }
                teams[teamId - 1].money += players[playerId - 1].price;
                printf("player sold succesfully\n");
            }
        }
        else if (strcmp(cmd, "match") == 0)
        {
            int teamId1, teamId2;
            scanf("%d %d", &teamId1, &teamId2);
            if (teamId1 > countOfTeams || teamId1 < 1 || teamId2 > countOfTeams || teamId2 < 1)
                printf("team doesnt exist\n");
            else if (teams[teamId1 - 1].playersCount < 11 || teams[teamId2 - 1].playersCount < 11)
                printf("the game can not be held due to loss of the players\n");
            else
            {
                int power1 = 0, power2 = 0;
                int num1 = 0, num2 = 0;
                for (int i = 0; i < PLAYERSCOUNT; i++)
                {
                    int playerId = teams[teamId1 - 1].players[i];
                    if (playerId != -1 && num1 < 11)
                    {
                        power1 += players[playerId - 1].speed;
                        power1 += players[playerId - 1].finishing;
                        num1++;
                    }
                    playerId = teams[teamId2 - 1].players[i];
                    if (playerId != -1 && num2 < 11)
                    {
                        power2 += players[playerId - 1].speed;
                        power2 += players[playerId - 1].defence;
                        num2++;
                    }
                    if (num1 == 11 && num2 == 12)
                        break;
                }
                if (power1 > power2)
                {
                    teams[teamId1 - 1].wins++;
                    teams[teamId2 - 1].loses++;
                }
                else if (power2 > power1)
                {
                    teams[teamId2 - 1].wins++;
                    teams[teamId1 - 1].loses++;
                }
                else
                {
                    teams[teamId2 - 1].eqs++;
                    teams[teamId1 - 1].eqs++;
                }
            }
        }
        else if (strcmp(cmd, "rank") == 0)
        {
            team* sortedTeams = (team*)malloc(sizeof(team) * countOfTeams);
            memcpy(sortedTeams, teams, sizeof(team) * countOfTeams);
            for (int i = 0; i < countOfTeams; i++)
            {
                for (int j = i+1; j < countOfTeams; j++)
                {
                    if((sortedTeams[j].wins > sortedTeams[i].wins))
                    {
                        swapStrings(sortedTeams[j].name, sortedTeams[i].name);
                    }
                    else if(sortedTeams[j]. wins == sortedTeams[i].wins){
                        if(sortedTeams[j].eqs > sortedTeams[i].eqs){
                            swapStrings(sortedTeams[j].name, sortedTeams[i].name);
                        }
                        else if(sortedTeams[j].eqs == sortedTeams[i].eqs)
                        {
                            if(sortedTeams[j].loses < sortedTeams[i].loses)
                                swapStrings(sortedTeams[j].name, sortedTeams[i].name);
                        }
                    }
                }
            }
            for (int i = 0; i < countOfTeams; i++)
                printf("%d. %s\n", i+1, sortedTeams[i].name);
            free(sortedTeams);
        }
    } while (strcmp(cmd, "end"));
    return 0;
}

