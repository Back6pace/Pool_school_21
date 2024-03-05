#!/bin/bash
echo "Укажите путь до файла который нужно протестировать src/file, вы можете скопировать нужный файл"
ls
read path

cd $path
if ["$path" == ""]; then 
    echo "Вы ввели пустую строку"
    exit 1
fi

file_name=$(basename $path)

echo "------- gcc -Wall -Werror -Wextra : создание исполняемого файла -------"
gcc -Wall -Werror -Wextra $file_name

echo "------- cppcheck - Проверка -------"
cppcheck --enable=all --suppress=missingIncludeSystem $file_name

echo "------- clang-format -i : Исправление ошибок -------"
clang-format -i $file_name

echo "------- leaks -atExit -- : Проверка на утечку данных -------"
leaks -atExit -- ./a.out

echo "Проверка завершена"
