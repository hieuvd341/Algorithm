void __fastcall register()
{
    struct user *new_user; // rbx
    struct user *v1;       // rbx
    int id;                // [rsp+4h] [rbp-4Ch]
    int i;                 // [rsp+8h] [rbp-48h]
    int j;                 // [rsp+Ch] [rbp-44h]
    char user_input[40];   // [rsp+10h] [rbp-40h] BYREF
    unsigned __int64 v6;   // [rsp+38h] [rbp-18h]

    v6 = __readfsqword(0x28u);
    id = -1;
    printf("Please input username\n> ");
    read_string(user_input, 31);
    for (i = 0; i <= 4; ++i)
    {
        if (users[i] && !strcmp(users[i]->username, user_input))
        {
            puts("[-] This user already registerd");
            return;
        }
    }
    for (j = 0; j <= 4; ++j)
    {
        if (!users[j])
        {
            id = j;
            break;
        }
    }
    if (id == -1)
    {
        puts("[-] User Registration is over");
        exit(0);
    }
    users[id] = malloc(0x20uLL);
    new_user = users[id];
    new_user->username = malloc(0x20uLL);
    v1 = users[id];
    v1->password = malloc(0x20uLL);
    users[id]->money = 0x3B9ACA00LL;
    users[id]->transaction = 0LL;
    strncpy(users[id]->username, user_input, 31uLL);
    printf("Please input password\n> ");
    read_string(users[id]->password, 31);
    printf("Verify input password\n> ");
    read_string(user_input, 31);
    if (!strcmp(users[id]->password, user_input))
    {
        puts("[+] Registration success");
    }
    else
    {
        puts("[-] Password confirmation failed"); // uaf
        free(users[id]->username);
        free(users[id]->password);
        free(users[id]);
        users[id] = 0LL;
    }
}