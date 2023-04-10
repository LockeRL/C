from tkinter import *
from tkinter.messagebox import showerror, showinfo
from task import fib, make_uniq_match


def show_info():
    showinfo(title="Что делает программа?", message="Программа предназначена для вывода чисел Фибоначчи и "
                                                    "поиска неповторяющихся элементов массива")


def show_creator():
    showinfo(title="Информация о создателе", message="Сидоров Максим ИУ7-32Б")


def clear():
    fib_input.delete(0, END)
    arr_input.delete(0, END)
    table_fib.config(state="normal")
    table_fib.delete(0.0, END)
    table_fib.config(state="disabled")
    table_uniq.config(state="normal")
    table_uniq.delete(0.0, END)
    table_uniq.config(state="disabled")


def check_number(n):
    try:
        int(n)
    except:
        return False
    return True


def print_fib(event):
    if not check_number(fib_input.get()):
        showerror(title='Некорректное число!', message='Некорректное число!')
        return

    n = int(fib_input.get())

    a = list(fib(n))
    table_fib.config(state="normal")
    table_fib.delete(0.0, END)
    table_fib.insert(0.0, f"{a}")
    table_fib.config(state="disabled")


def print_uniq(event):
    try:
        a = list(map(int, arr_input.get().split(',')))
    except:
        showerror(title='Невозможно преобразовать в массив!', message='Невозможно преобразовать в массив!')
        return

    b = list(make_uniq_match(a))
    table_uniq.config(state="normal")
    table_uniq.delete(0.0, END)
    table_uniq.insert(0.0, f"{b}")
    table_uniq.config(state="disabled")


window = Tk()

# Создание окна
window.title('Лабораторная 12')
window.geometry('600x280+50+100')
window.resizable(width=False, height=False)

# Создание верхнего меню
mainmenu = Menu(window)
window.config(menu=mainmenu)

infomenu = Menu(mainmenu, tearoff=0)
infomenu.add_command(label="О программе", command=show_info)
infomenu.add_command(label="О создателе", command=show_creator)

mainmenu.add_cascade(label="Очистить поля", command=clear)
mainmenu.add_cascade(label="Справка", menu=infomenu)

# Создание полей и кнопок
table_fib = Text(window)
table_fib.place(x=5, y=40, width=480, height=80)

table_uniq = Text(window)
table_uniq.place(x=5, y=190, width=480, height=80)

fib_label = Label(window, text='Введите количество чисел Фибоначчи:', font='Arial 12')
fib_label.place(x=5, y=5)
fib_input = Entry(window, background='white', font='Arial 12')
fib_input.place(x=295, y=5, width=60, height=30)

arr_label = Label(window, text='Поиск первых вхождений чисел.', font='Arial 12')
arr_label.place(x=5, y=130)
arr_label_2 = Label(window, text='Введите числа через запятую:', font='Arial 12')
arr_label_2.place(x=5, y=155)
arr_input = Entry(window, background='white', font='Arial 12')
arr_input.place(x=230, y=155, width=200, height=30)


fib_btn = Button(text='Вывести числа', font=('Arial', '12'))
fib_btn.bind('<Button-1>', print_fib)
fib_btn.place(x=360, y=5, width=150, height=30)

uniq_btn = Button(text='Вывести числа', font=('Arial', '12'))
uniq_btn.bind('<Button-1>', print_uniq)
uniq_btn.place(x=440, y=155, width=150, height=30)

window.mainloop()