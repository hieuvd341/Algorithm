x = int(input())
s = ""

def deQuy(s:str):
    if len(s) == x:
        print(s)
        return
    if s =="" or s[-1] == '0':
        deQuy(s+'0')
        deQuy(s+'1')
        
    else:
        deQuy(s+'0')

deQuy(s)