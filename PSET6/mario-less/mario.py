# prototype
def main():

    height = get_height()
    draw(height, height)


# printing the pyramid
def draw(height, h):
    if height == 0:
        return
    draw(height - 1, h)
    print(" " * (h - height), end='')
    print("#" * height)


# prompting the user for height
def get_height():
    while True:
        try:
            height = int(input("Height: "))
            if (height > 0 and height < 9):
                break
        except ValueError:
            None

    return height


# retun main function
main()
