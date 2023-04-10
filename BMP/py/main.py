from tkinter import *
from tkinter.messagebox import showerror, showinfo
from bmp_lib import process
from tkinter import filedialog


def show_info():
    showinfo(title="Что делает программа?", message="Программа предназначена для обработки bmp24 файлов")


def show_creator():
    showinfo(title="Информация о создателе", message="Сидоров Максим ИУ7-32Б")


def check_number(n):
    try:
        a = int(n)
    except:
        a = 0
    return a


def chose_photo(event):
    global photo_src
    global photo_src_correct

    photo_src = filedialog.askopenfilename()

    length = len(photo_src)

    if photo_src[length - 4:length] == '.bmp':
        photo_not_chosen_label.place_forget()
        photo_chosen_label.place(x=180, y=4)
        photo_src_correct = True
    else:
        photo_chosen_label.place_forget()
        photo_not_chosen_label.place(x=180, y=4)
        photo_src_correct = False


def chose_dst_photo(event):
    global photo_dst
    global photo_dst_correct

    photo_dst = filedialog.asksaveasfilename()
    if photo_dst is None or photo_dst == "" or len(photo_dst) == 0:
        photo_dst_chosen_label.place_forget()
        photo_dst_not_chosen_label.place(x=250, y=40)
        photo_dst_correct = False
    else:
        photo_dst_not_chosen_label.place_forget()
        photo_dst_chosen_label.place(x=250, y=40)
        length = len(photo_dst)
        if not photo_src[length - 4:length] == '.bmp':
            photo_dst += ".bmp"
        photo_dst_correct = True


def place_user_entry():
    n_label.place(x=5, y=290)
    n.place(x=30, y=294, height=20, width=20)
    m_label.place(x=60, y=290)
    m.place(x=85, y=294, height=20, width=20)
    core_label.place(x=5, y=315)
    core.place(x=5, y=340, height=30, width=250)


def destroy_user_entry():
    n_label.place_forget()
    n.place_forget()
    m.place_forget()
    m_label.place_forget()
    core.place_forget()
    core_label.place_forget()


def check_arr():
    try:
        a = list(map(float, core.get().split()))
        if len(a) == 0 or len(a) < check_number(n.get()) * check_number(m.get()):
            a = None
    except:
        a = None
    return a


def create_img(event):
    if photo_dst_correct is False:
        photo_dst_chosen_label.place_forget()
        photo_dst_not_chosen_label.place(x=250, y=40)

    if photo_src_correct is False:
        photo_chosen_label.place_forget()
        photo_not_chosen_label.place(x=180, y=4)

    if photo_src_correct and photo_src_correct and var.get() > 0:
        n_num = check_number(n.get())
        m_num = check_number(m.get())
        arr = check_arr()
        print(process(photo_src, photo_dst, var.get(), arr, n_num, m_num))



window = Tk()

photo_src = ''
photo_dst = ''
photo_src_correct = False
photo_dst_correct = False

# Создание окна
window.title('Обработка bmp24')
window.geometry('400x500+50+100')
window.resizable(width=False, height=False)

# Создание верхнего меню
mainmenu = Menu(window)
window.config(menu=mainmenu)

infomenu = Menu(mainmenu, tearoff=0)
infomenu.add_command(label="О программе", command=show_info)
infomenu.add_command(label="О создателе", command=show_creator)

mainmenu.add_cascade(label="Справка", menu=infomenu)

# Создание полей и кнопок
photo_chosen_label = Label(window, text='Фото выбрано', font=("Courier bold", 12), fg="green")
photo_not_chosen_label = Label(window, text='Фото не выбрано', font=("Courier bold", 12), fg="red")

photo_src_btn = Button(text='Выберите фото', font=('Arial', '12'))
photo_src_btn.bind('<Button-1>', chose_photo)
photo_src_btn.place(x=5, y=5, width=150, height=25)

photo_dst_chosen_label = Label(window, text='Путь выбран', font=("Courier bold", 12), fg="green")
photo_dst_not_chosen_label = Label(window, text='Путь не выбран', font=("Courier bold", 12), fg="red")

photo_dst_btn = Button(text='Выбрать путь сохранения', font=('Arial', '12'))
photo_dst_btn.bind('<Button-1>', chose_dst_photo)
photo_dst_btn.place(x=5, y=40, width=230, height=25)

# Операции с изображением
operations_label = Label(window, text='Операции с изображением', font=("Courier bold", 15))
operations_label.place(x=5, y=80)

var = IntVar()
var.set(0)
greyscale = Radiobutton(text="Оттенки серого", font=('Arial', '12'), variable=var, value=1, command=destroy_user_entry)
greyscale.place(x=5, y=110)

sobel = Radiobutton(text="Оператор Собеля", font=('Arial', '12'), variable=var, value=2, command=destroy_user_entry)
sobel.place(x=5, y=135)

laplas = Radiobutton(text="Оператор Лапласа", font=('Arial', '12'), variable=var, value=3, command=destroy_user_entry)
laplas.place(x=5, y=160)

gauss = Radiobutton(text="Размытие по Гауссу", font=('Arial', '12'), variable=var, value=4, command=destroy_user_entry)
gauss.place(x=5, y=185)

border = Radiobutton(text="Выделение границ", font=('Arial', '12'), variable=var, value=5, command=destroy_user_entry)
border.place(x=5, y=210)

median = Radiobutton(text="Медианный фильтр", font=('Arial', '12'), variable=var, value=7, command=destroy_user_entry)
median.place(x=5, y=235)

user_core = Radiobutton(text="Пользовательское ядро", font=('Arial', '12'), variable=var, value=6,
                        command=place_user_entry)
user_core.place(x=5, y=260)

# Пользовательский ввод ядра
n_label = Label(window, text='N:', font=("Courier bold", 12))
n = Entry(window, font=("Courier", 12, "bold"))

m_label = Label(window, text='M:', font=("Courier bold", 12))
m = Entry(window, font=("Courier", 12, "bold"))

core_label = Label(window, text='Введите элементы ядра через пробел:', font=("Courier bold", 12))
core = Entry(window, font=("Courier", 12, "bold"))

# Кнопка получения изображения
make_photo_btn = Button(text='Получить изображение', font=('Arial', '12'))
make_photo_btn.bind('<Button-1>', create_img)
make_photo_btn.place(x=5, y=380, width=230, height=25)

window.mainloop()