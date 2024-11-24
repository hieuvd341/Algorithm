__int64 __fastcall delete_user(struct user *user)
{
    int id;                          // [rsp+18h] [rbp-18h]
    int i;                           // [rsp+1Ch] [rbp-14h]
    struct transaction *transaction; // [rsp+20h] [rbp-10h]
    struct transaction *ptr;         // [rsp+28h] [rbp-8h]

    id = -1;
    for (i = 0; i <= 4; ++i)
    {
        if (users[i] == user)
        {
            id = i;
            break;
        }
    }
    free(user->username);
    free(user->password);
    if (user->transaction)
    {
        transaction = user->transaction;
        while (1)
        {
            delete_transaction(transaction->partner, transaction->transactionID); // free partner transaction
            if (!transaction->next)
                break;
            ptr = transaction;
            transaction = transaction->next;
            ptr->partner = 0LL;
            ptr->next = 0LL;
            free(ptr); // free transaction
        }
        free(transaction);
    }
    else
    {
        puts("[-] No transaction");
    }
    free(user);
    users[id] = 0LL;
    return 0LL;
}