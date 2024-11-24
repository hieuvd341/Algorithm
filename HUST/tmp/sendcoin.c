// send coin to user2
__int64 __fastcall sendcoin(user *user1)
{
  int i;                            // [rsp+18h] [rbp-58h]
  int amount;                       // [rsp+1Ch] [rbp-54h]
  struct transaction *j;            // [rsp+20h] [rbp-50h]
  struct transaction *k;            // [rsp+20h] [rbp-50h]
  struct user *user2;               // [rsp+28h] [rbp-48h]
  struct transaction *transaction1; // [rsp+30h] [rbp-40h]
  transaction *transaction2;        // [rsp+38h] [rbp-38h]
  char user_input[40];              // [rsp+40h] [rbp-30h] BYREF
  unsigned __int64 canary;          // [rsp+68h] [rbp-8h]

  canary = __readfsqword(0x28u);
  if (transactionID > 0x64)
  {
    puts("[-] Transaction is over");
    exit(1);
  }
  printf("What user do you send to?\n> ");

  // find recv user
  read_string(user_input, 31);
  for (i = 0;; ++i)
  {
    if (i > 4)
    {
      puts("[-] This user is not registered");
      return 1LL;
    }
    if (users[i] && !strcmp(users[i]->username, user_input))
      break;
  }
  user2 = users[i];

  printf("Hom many?\n> ");
  read(0, user_input, 0x14uLL);
  amount = atol(user_input);

  if (amount > 0 && user1->money - amount >= 0)
  {
    transaction2 = malloc(0x28uLL);
    transaction2->next = 0LL;
    transaction2->partner = user1;
    transaction2->amount = amount;
    transaction2->transactionID = transactionID;
    transaction2->flow = 1LL;
    user2->money += amount;

    if (user2->transaction) // add transaction to user2's transaction linked list
    {
      for (j = user2->transaction; j->next; j = j->next)
        ;
      j->next = transaction2;
    }
    else
    {
      user2->transaction = transaction2;
    }

    transaction1 = malloc(0x28uLL);
    transaction1->next = 0LL;
    transaction1->partner = user2;
    transaction1->amount = amount;
    transaction1->transactionID = transactionID;
    transaction1->flow = 0LL;
    user1->money -= amount;
    ++transactionID;
    if (user1->transaction)
    {
      for (k = user1->transaction; k->next; k = k->next)
        ;
      k->next = transaction1;
    }
    else // add transaction to user1's transaction linked list
    {
      user1->transaction = transaction1;
    }
    puts("[+] Transaction success");
    return 0LL;
  }
  else
  {
    puts("[-] Can't execute this transaction");
    return 1LL;
  }
}