if [ -f ba.sh ];
    then
    echo time to work;
    else
    echo still have time to party;
fi

for i in 1 2 3
    do touch backup.$i
        done

for i in {3..1} 
    do mv backup.$i backup.`expr $i + 1`
done

for person in `who | cut -d ' ' -f1 | sort -u`
    do mail $person < message
    done

color=(red blue yellow)
echo $color
echo ${color[2]}
