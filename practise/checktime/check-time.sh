#! /bin/bash

# ####################   使用前请阅读   ###########################
# 
# 支持的日志格式
# Time Threadid Level Message
# Time 格式 YYYY-MM-DD HH:MM:SS:UUUUUU
# 日志示例
# 2018-12-25 11:39:51:813182 140681049798400 [INFO]   [mrcp_recog_state_machine.c:0425][recog_request_state_update] Process RECOGNIZE Request <bc8812a607f611e9@speechrecog> [1]
#
# 使用之前请确认日志格式
# 同时必须满足以下要求
# 1，每一行包含 keyword 和 id，使用id来确认一个请求过程
# 2，这个请求过程的不同的步骤一般用 keyword 来区分，使用方式见实现。
#
# 在 unimrcp 的日志中, 这个 id 是 sessionid, 比如 <24a0b58c07f711e9>
#
# ################################################################


# ############################################################
#
# 输出信息
# 1，每秒的请求数
# 2，每秒正在执行的 session 数，(并发数?)
#
# ############################################################


# 逻辑执行步骤 ##########################################
#
#
#
#
#
# ########################################################

# 所有需要查找的关键字
# 按照在一个session中出现的顺序填写
# 这些关键字所在的行必须要有 sessionid，以标识它们是同一个 session
keywords[0]="Add Session"
keywords[1]="Send Answer"
keywords[2]="Process RECOGNIZE Request"
keywords[3]="Destroy Session"
keywords[4]=""
# total keyword count, equal to element number of keywords array.
keywords_count=4

# 在 unimrcp 中，可能没有 RECOGNITION-COMPLETE Event.
#keywords="Process RECOGNITION-COMPLETE Event"

# log file name pattern
# 日志文件的文件名模式
log_file_name_pattern="unimrcpserver*.log"
echo "log file name pattern: [$log_file_name_pattern]"

# sessionid regular pattern
# 粗略找出id字符串，包含其它标识符
sessionidpattern1="<[0-9a-z]{16}[>@]"
# 从上面的模式中精确找出id
sessionidpattern2="[0-9a-z]{16}"

# 日期和时间的格式
# TODO
# 暂时未实现
# 总的日期格式，每一行都需要包含这样的格式
datetimepattern1="^[0-9]{4}-[0-9]{2}-[0-9]{2} ([0-9]{2}:){2}[0-9]{2}:[0-9]{3}"
# 总的日期格式中，需要转换成秒数的日期时间
datetimepattern_second="[0-9]{4}-[0-9]{2}-[0-9]{2} ([0-9]{2}:){2}[0-9]{2}"
# 总的日期格式中，毫秒数
datetimepattern_usecond="[0-9]{3}$"

check()
{
    if [ $? != 0 ];
    then
        echo "ERROR, $1"
        exit 1
    fi
}

check_msg()
{
    if [ $? != 0 ];
    then
        echo ERROR $1
    fi
}

check_equal()
{
    if [ $1 != $2 ];then
        echo "ERROR not equal, $1 != $2, $3"
        exit 1
    fi
}



# replace spaceblank with '_'.
for ((i=0; i<keywords_count; i++ ))
do
    keyword="${keywords[$i]}"
    t_keyword=`echo ${keyword} | awk 'BEGIN{ORS="";}{for(i=1; i<=NF; i++) if (i!=NF) print $i "_"; else print $i;}'`
    keywords_filename[$i]=$t_keyword
    filename2[$i]="2_${t_keyword}.txt"
    filename3[$i]="3_${t_keyword}.txt"
    filename5[$i]="5_${t_keyword}.txt"
    filename6[$i]="6_${t_keyword}.txt"
done

# convert keywords array to regular pattern string.
keyword_reg=""
for ((i=0; i<keywords_count; i++))
do
    keyword_reg+=${keywords[$i]}
    if (( i != keywords_count - 1))
    then
        keyword_reg+="|"
    fi
done
echo $keyword_reg

    date 

echo "--1--"
# 根据关键字从日志文件中获取到所有行
# 1_total_session.txt
k_total_session_file="1_total_session.txt"
k_total_sessionid_file="1_1_total_sessionid.txt"
k_sessionid_count_file="1_2_sessionid_count.txt"
k_complete_session_file="1_3_complete_session.txt"
k_incomplete_session_file="1_3_incomplete_session.txt"
if [ ! -f $k_total_session_file ]
then
    for filepath in `ls -rt $log_file_name_pattern`
    do
        echo "$filepath"
        grep -E "$keyword_reg" $filepath >> $k_total_session_file
        check "$filepath"
    done

    date 

    datetime_file="1_datetime.txt"
    message_file="1_message.txt"
    awk '{print $1,$2}' $k_total_session_file > "$datetime_file"
    awk 'BEGIN{ORS=" ";}{if (NF>5){ for(i=6; i<=NF; i++) print $i; print "\n"; }}' $k_total_session_file > "$message_file"
    sed -i "s/^ //g" $message_file

    t_lineno=`wc -l $datetime_file | awk '{print $1}'`
    m_lineno=`wc -l $message_file | awk '{print $1}'`
    check_equal $t_lineno $m_lineno "日期开头的行和信息行不同，一般是日志格式不同"

    paste $datetime_file $message_file > $k_total_session_file
    # rm $datetime_file $message_file -f

    date 

    # 检查所有的行是否都是日期开头
    t_lineno=`grep -E "$datetimepattern1" $k_total_session_file -c`
    m_lineno=`wc -l $k_total_session_file | awk '{print $1}'`
    check_equal $t_lineno $m_lineno "有的行不是以日期时间开头"

    echo "--1.1--"
    # 根据 session id 的正则配置规则获取包含关键字的行的 session id
    # get total session id
    grep -Eo "$sessionidpattern1" ${k_total_session_file} | grep -Eo "$sessionidpattern2" > $k_total_sessionid_file

    t_lineno=`wc -l $k_total_session_file | awk '{print $1}'`
    m_lineno=`wc -l $k_total_sessionid_file | awk '{print $1}'`
    check_equal $t_lineno $m_lineno "有的行不存在 session id "

    date 

    echo "--1.2--"
    # 获取每一个 session id 出现的次数
    # 和 k_total_sessionid_file 中的 session id 行行对应
    awk -v keywordscount=$keywords_count ' \
        BEGIN                 \
        {                     \
            sid_count=0;      \
            line_count=0;     \
        }                     \
        {                     \
            t_sid[line_count]=$1; \
            line_count++;         \
            if(s[$1] == "")   \
            {                 \
                s[$1]=1;      \
            }                 \
            else                \
            {                   \
                s[$1]=s[$1]+1;  \
            }                   \
        }                       \
        END                     \
        {                       \
            for(i=0; i< line_count; i++)\
            {                           \
                sid=t_sid[i];           \
                print s[sid];           \
            }                           \
        }' $k_total_sessionid_file > $k_sessionid_count_file

    t_lineno=`wc -l $k_sessionid_count_file | awk '{print $1}'`
    m_lineno=`wc -l $k_total_sessionid_file | awk '{print $1}'`
    check_equal $t_lineno $m_lineno "awk 语句错误"

    date 

    echo "--1.3--"
    # 将所有包含关键字的行按照 session 的过程分为完整的和不完整的
    # 步骤3只处理计算完整的 session 的过程。
    declare -a session_id_count
    index=0
    for sidcount in `cat $k_sessionid_count_file`
    do
        session_id_count[$index]=$sidcount
        let index=($index+1)
    done

    date 

    index=0
    # get complete seeesion and incomplete session
    while read line
    do
        if [ ${session_id_count[$index]} == $keywords_count ];then
            echo "$line" >> $k_complete_session_file
        else
            echo "$line" >> $k_incomplete_session_file
        fi
        let index=($index+1)
    done < $k_total_session_file
    unset session_id_count

    date 

    echo "1 step finished, get $k_total_session_file"
else
    echo "1 step finished, has $k_total_session_file already"
fi

csid=`wc -l $k_complete_session_file | awk '{print $1}'`
icsid=`wc -l $k_incomplete_session_file | awk '{print $1}'`
let tcsid=($csid+$icsid)
if [ $csid'x' == 'x' ];then
    echo "ERROR, NO complete session"
    exit 1
fi

if [ $tcsid'x' == 'x' ];then
    echo "ERROR"
    exit 1
fi

tsid=`wc -l $k_total_session_file | awk '{print $1}'`
if [ $tsid != $tcsid ];then
    echo "ERROR"
    exit 1
fi

#---------------------------------------------------------------------------------

echo "--2--"
# 获取完整 session 中的每个关键字对应的所有的行，然后保存到以关键字命名的文件中
# 2, get split file from k_total_session_file by keywords
k_filename2="${filename2[0]}"
if [ ! -f "$k_filename2" ];then
    for ((i=0; i < keywords_count; i++))
    do
        grep "${keywords[$i]}" ${k_complete_session_file} > ${filename2[$i]}
        check "$keywords_count"
    done
    echo "2 step finished, get split files."
else
    echo "2 step finished, has split files already."
fi

    date 

# 获取所有完整 session 的个数
sid_count=`wc -l $k_complete_session_file | awk '{print $1}'`
let sid_count=($sid_count/$keywords_count)
echo "sid_count: $sid_count"

lostcount=0
echo "--3--"
date 

k_filename3="${filename3[0]}"
k_filename31="3_wholesessionid.txt"
# 从关键字文件中获取session，保存到以关键字命名的文件中
rm $k_filename31 -rf
if [ ! -f "$k_filename3" ];then
    declare -a wholefileindex_array
    declare -a fileindex_array

    echo "---3.1---"
    index=0
    for ((i=0; i<keywords_count; i++))
    do
        filepath=${filename2[$i]}
        let tindex=($i*2)
        fileindex_array[$tindex]=$index
        let index=($index+$sid_count)
        let tindex=($i*2+1)
        fileindex_array[$tindex]=$index
        grep -Eo "$sessionidpattern1" $filepath | grep -Eo "$sessionidpattern2" >> $k_filename31
    done

    date 

    echo "---3.2---"
    # 以第一个关键字出现的顺序为目标顺序
    # 将其他关键字按照此顺序重排
    # 获取到重排的索引
    # 此处获取到的是，当前行是key，应该放到的行是值
    # 期望获取的是，应该放到的行是key，当前行的值
    # get resorted index of each file.
    index=0
    tindex=0
    wholefileindex_file="3_2_wholefileindex.txt"
    awk -v tcount=$sid_count '{if(FNR<=tcount) { s[$1]=FNR-1; print FNR-1; } else { if (s[$1] == "" ) print "hello"; else print s[$1]; } }' $k_filename31 > $wholefileindex_file

    grep -i hello $wholefileindex_file > /dev/null
    if [ $? == 0 ];then
        echo "ERROR"
        exit 1
    fi

    t_lineno=`wc -l $k_filename31 | awk '{print $1}'`
    m_lineno=`wc -l $wholefileindex_file | awk '{print $1}'`
    check_equal $t_lineno $m_lineno "错误"

    date 

    rwholefileindex_file="3_2_rwholefileindex.txt"
    awk -v tcount=$sid_count 'BEGIN{chunk=0;linecount=0;s[0]=0;}{linecount++; key=FNR-1; value=$1; chunk=int(key/tcount); rkey=value+chunk*tcount; rvalue=key%tcount; s[rkey]=rvalue;}END{for(i=0;i<linecount;i++) print s[i]}' $wholefileindex_file > $rwholefileindex_file
    declare -a r_wholefileindex_array
    index=0
    while read line
    do
        r_wholefileindex_array[$index]=$line
        let index=($index+1)
    done < $rwholefileindex_file

    t_lineno=`wc -l $rwholefileindex_file | awk '{print $1}'`
    m_lineno=`wc -l $wholefileindex_file | awk '{print $1}'`
    check_equal $t_lineno $m_lineno "错误"

    # 根据重排索引进行重排
    # 获取不同关键字文件的行行对应
    # read all file and resort it.
    echo "---3.3---"
    # first file, base file.
    cp ${filename2[0]}  ${filename3[0]}
    for ((i=1; i<keywords_count; i++))
    do
        date

        declare -a fileline_array
        # read one file in array.
        filepath=${filename2[$i]}
        index=0
        while read line
        do
            fileline_array[$index]="$line"
            let index=($index+1)
        done < $filepath

        let tindex=($i*2)
        startindex=${fileindex_array[$tindex]}
        let tindex=($i*2+1)
        endindex=${fileindex_array[$tindex]}

        date

        for ((tindex=startindex; tindex < endindex; tindex++))
        do
            result_index="${r_wholefileindex_array[$tindex]}"
            echo "${fileline_array[$result_index]}" >> ${filename3[$i]}
        done
        unset fileline_array
    done

    date 

    unset wholefileindex_array
    unset fileindex_array
    ###############################################
    echo "3 step finished, get sorted sessionid file each keywords."
else
    echo "3 step finished, has sorted sessionid file each keywords already."
fi

echo "--4--"
echo "4 step finished."

echo "--5--"
# 获取时间字符串，
# 以下实现只计算时分秒，没有计算年月日
k_filename5="${filename5[0]}"
if [ ! -f "$k_filename5" ];then
    for ((i=0; i < keywords_count; i++))
    do
        awk '{print $2}' ${filename3[$i]} > ${filename5[$i]}
        check "$i"
    done
    echo "5 step finished, get time each keywords."
else
    echo "5 step finished, has time each keywords already."
fi

    date 

echo "--6--"
# 将二十四小时制的时间字符串转换成毫秒数
# 以下实现只计算时分秒，没有计算年月日
k_filename6="${filename6[0]}"
if [ ! -f "$k_filename6" ];then
    for ((i=0; i < keywords_count; i++))
    do
        awk -F :  '{sec=$1*60*60+$2*60+$3; msec=int($4/1000); msec=msec+(sec*1000); print msec;}'  ${filename5[$i]} > ${filename6[$i]}
    done
    echo "6 step finished, get second each keywords."
else
    echo "6 step finished, has second each keywords already."
fi

    date 

echo "--7--"
# 将每个步骤的毫秒数按行对应的关系放置到同一文件中
k_filename7="7_wholetimes.txt"
if [ ! -f "$k_filename7" ];then
    for ((i=0; i < keywords_count; i++))
    do
        wholefilelist="$wholefilelist"" ""${filename6[$i]}"
    done
    paste $wholefilelist > $k_filename7
    echo "7 step finished, get second each keywords."
else
    echo "7 step finished, has second each keywords already."
fi

    date 

echo "--8--"
# 计算每个步骤的时间差
# 计算从开始那一步到此步骤的时间差
# 输出文件的时间格式
# t1 t2 t3 t4 d1 d2 d3 c1 c2 c3
# 其中 t* 是当前步骤的毫秒数
#      d* 是当前步到下一步的时间差，d2 是第二步到第三步的时间差
#      c* 是第一步到下一步的时间差，c2 是第一步到第三步的时间差
k_filename8="8_wholetimes.txt"
if [ ! -f "$k_filename8" ];then
    awk -F '\t' 'BEGIN{ORS="\t";}{for(i=1;i<=NF;i++) print $i; for(i=2;i<=NF;i++) print $i-$(i-1); for(i=2;i<=NF;i++) print $i-$1; print "\n";}' $k_filename7 > $k_filename8
    sed -i 's/^\t//g' $k_filename8
    echo "8 step finished, get second each keywords."
else
    echo "8 step finished, has second each keywords already."
fi

    date 

echo "--9--"
# 计算每秒的请求数
echo "get request number every second, pps"
k_filename9="9_pps.txt"
if [ ! -f "$k_filename9" ];then
    awk 'BEGIN              \
            {               \
                last=0;     \
                count=0;    \
            }               \
            {
                this=int($1/1000);         \
                if(last==0) last=this-1;   \
                if (this != last ){        \
                    count++;               \
                    print last, count;     \
                    for(i=last+1;i<this;i++)\
                        print i, 0;\
                    count = 0;     \
                }                  \
                else count++;      \
                last = this;       \
            }                   \
        END                     \
            {                   \
                count++;        \
                print last, count;  \
            }                   \
        ' $k_filename8 > $k_filename9

    stat=`awk 'BEGIN {ac=0;mc=0;count=0;} {count++;if(mc<$2) mc=$2; ac+=$2;} END{print "max_count:",mc;print "avg_count:",ac/count;}' $k_filename9`
    echo $stat >> $k_filename9
    echo "请求数:"
    echo $stat
    echo "9 step finished, get second each keywords."
else
    echo "9 step finished, has second each keywords already."
fi

    date 

echo "--10--"
# 计算每秒的并发数
echo "get working number every second"
k_filename10="10_pps.txt"
filename10_t="10_wholesecond.txt"
if [ ! -f "$k_filename10" ];then
    # get start time array
    declare -a stime
    declare -a etime
    scount=0
    for tt in `awk '{print $1;}' $k_filename8`
    do
        stime[$scount]=$tt
        let scount=($scount+1)
    done

    # get end time array
    ecount=0
    for tt in `awk -v kcount=$keywords_count '{print $kcount;}' $k_filename8`
    do
        etime[$ecount]=$tt
        let ecount=($ecount+1)
    done

    if [ $scount != $ecount ]; then
        echo "ERROR, starttime count: $scount, endtime count: $ecount"
        exit 1
    fi

    date 

    echo "total count: $scount,$ecount"

    for (( j=0; j < scount; j++ ))
    do
        starttime=${stime[$j]}
        let starttime=($starttime/1000)
        endtime=${etime[$j]}
        let endtime=($endtime/1000)
        for ((i=starttime; i <= endtime; i++))
        do
            echo $i >> $filename10_t
        done
    done

    date 

    awk '           \
    BEGIN           \
    {               \
        count=0;    \
    }               \
    {                       \
        if(s[$1] == "" )    \
        {                   \
            s[$1]=1;        \
            c[count]=$1;    \
            count++;        \
        }                   \
        else                \
        {                   \
            s[$1]=s[$1]+1;  \
        }                   \
    }                       \
    END                     \
    {                       \
        mc=0;               \
        ac=0;               \
        for(i=0;i<count;i++)    \
        {                       \
            t=c[i];             \
            print c[i], s[t];   \
            ac += s[t];         \
            if (mc < s[t])      \
                mc = s[t];      \
        }                       \
        print "max_count:", mc;       \
        print "avg_count:", ac/count; \
    }' $filename10_t > $k_filename10

    date 

    echo "并发数:"
    tail -n 2 $k_filename10

    unset stime
    unset etime

    echo "10 step finished, get second each keywords."
else
    echo "10 step finished, has second each keywords already."
fi

echo ""
echo "完整执行的session数: $sid_count"


    date 

exit 0

