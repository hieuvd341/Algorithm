x = int(input())
s = ""

def deQuy(s:str):
    if len(s) == x:
        print(s)
        return
    deQuy(s+'0')
    deQuy(s+'1')
        

deQuy(s)