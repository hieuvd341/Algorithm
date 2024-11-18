while True:
    try:
        text = input()
        x = text.upper()
        print(x)
    except EOFError:
        break