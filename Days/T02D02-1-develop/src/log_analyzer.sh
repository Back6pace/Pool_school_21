#!/bin/sh
parent=$(git rev-parse --show-toplevel)
cd $(git rev-parse --show-toplevel)
echo "Введите путь до файла формата folder/file"
read path
fullway="$parent/$path"

if ! [ -f "$fullway" ]; then
    echo "Ошибка, такого пути не существует"
    exit 1
fi 
filename=$(basename $path)
wordcount=$(wc -l $path | awk '{print $1}')
uniqstring=$(sort $path | uniq -u | wc -l)
unique_hashes_count=$(sort $path | awk '{print $8}' | uniq -u | wc -l)
dif_uniq_hash=$((uniqstring-unique_hashes_count))
echo $wordcount $uniqstring $dif_uniq_hash

