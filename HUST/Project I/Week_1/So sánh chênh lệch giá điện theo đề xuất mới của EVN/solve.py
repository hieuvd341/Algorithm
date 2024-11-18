x = int(input())
# Bang gia hien tai
if x <= 50 and x >=0:
    tien_cu= (x-0)*1728
elif x <=100:
    tien_cu  = 50*1728+(x-50)*1786
elif x <=200:
    tien_cu  = 50*1728+50*1786+(x-100)*2074
elif x <=300:
    tien_cu = 50*1728+50*1786+100*2074+(x-00)*2612
elif x <=400:
    tien_cu = 50*1728+50*1786+100*2074+100*2612+(x-300)*2919
else:
    tien_cu  = 50*1728+50*1786+100*2074+100*2612+100*2919+(x-400)*3015

# Bang gia moi
if x<=100:
    tien_moi = (x-0)*1728
elif x<=200:
    tien_moi = 100*1728+(x-100)*2074
elif x<=400:
    tien_moi = 100*1728+100*2074+(x-200)*2612
elif x<=700:
    tien_moi = 100*1728+100*2074+200*2612+(x-400)*3111
else:
    tien_moi = 100*1728+100*2074+200*2612+300*3111+(x-700)*3457
res = (tien_moi - tien_cu)*110/100
print(f"{res:.2f}")