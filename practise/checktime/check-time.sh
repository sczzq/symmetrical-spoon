#! /bin/bash

# ####################   使用前请阅读   ###########################
# 
# 作用，简单的提取和统计
# 以关键字提取日志文件的信息，
# 并简单统计基本数据
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
# 2，请求过程的不同的步骤一般用 keyword 来区分，使用方式见实现。
# 3，每个请求过程中每个关键字只出现一次，也即是没有重复的步骤。
# 4，只实现了计算当天的时间，不能处理两天的日志。 TODO
#
# 在 unimrcp 的日志中, 这个 id 是 sessionid, 比如 <24a0b58c07f711e9>
#
# ################################################################


# ############################################################
#
# 输出信息
# 1，每秒每关键字出现次数
# 2，每秒第一步到其他步骤之间存活数(并发数?)
#
# 如果只指定一个关键字，
# 那么只计算每秒的出现次数
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
log_filename_pattern='../unimrcp-100pps-500k-request/unimrcpserver*.log'
echo "log filename pattern: [$log_filename_pattern]"

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

# 日志行的通用格式中，以空格为分割符的field数
# 日志行示例
# 2018-12-25 11:39:51:813182 140681049798400 [INFO]   [mrcp_recog_state_machine.c:0425][recog_request_state_update] Process RECOGNIZE Request <bc8812a607f611e9@speechrecog> [1]
# 其中通用格式，即是行前缀格式
# 2018-12-25 11:39:51:813182 140681049798400 [INFO]   [mrcp_recog_state_machine.c:0425][recog_request_state_update]
# 日志消息格式
# Process RECOGNIZE Request <bc8812a607f611e9@speechrecog> [1]
# 那么，通用格式中共有四个空格分割符，共有5个field。
prefieldcount=5

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

check_lineno_equal()
{
	infile=$1
	outfile=$2
	msg=$3

	t_lineno=`wc -l $infile | awk '{print $1}'`
	m_lineno=`wc -l $outfile | awk '{print $1}'`
	check_equal $t_lineno $m_lineno $msg
}

# replace spaceblank with '_'.
for ((i=0; i<keywords_count; i++ ))
do
    keyword="${keywords[$i]}"
    t_keyword=`echo ${keyword} | awk 'BEGIN{ORS="";}{for(i=1; i<=NF; i++) if (i!=NF) print $i "_"; else print $i;}'`
    keywords_filename[$i]=$t_keyword
    filename6[$i]="6_${t_keyword}.txt"
    filename9[$i]="9_${t_keyword}.txt"
    filename10[$i]="10_${t_keyword}.txt"
    filename11[$i]="11_${t_keyword}.txt"
    filename12[$i]="12_${t_keyword}.txt"
    filename15[$i]="15_${t_keyword}.txt"
    filename16[$i]="16_${t_keyword}.txt"
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

# 根据关键字从日志文件中获取到所有行
# input  log file, pattern by log_filename_pattern.
# output  k1_total_session_file
function step1()
{
	echo "--1--"
	outfile=$1
	if [ ! -f "$outfile" ]
	then
		echo "start `date `"
		for filepath in `ls -rt $log_filename_pattern`
		do
			echo "$filepath"
			grep -E "$keyword_reg" $filepath >> $outfile
			check "$filepath"
		done
		echo "end `date `"
		echo "step finished, get"
	else
		echo "step finished, has already"
	fi
}

function step2()
{
	echo "--2--"
	infile=$1
	outfile=$2

	k2_datetime_file="2_datetime.txt"
	k2_message_file="2_message.txt"
	if [ ! -f $outfile ]
	then
		echo "start `date `"
		echo "start of get datetime, `date `"
		awk '{print $2}' $infile \
			| awk -F :  '\
			{\
				sec=$1*60*60+$2*60+$3;\
				msec=int($4/1000);\
				msec=msec+(sec*1000);\
				print msec;\
			}' > $k2_datetime_file 
		echo "end of get datetime, `date `"
		echo "start of get message, `date `"
		awk -v pfc=$prefieldcount '\
			BEGIN{}\
			{\
				if (NF>pfc)\
				{\
					ORS=" ";\
					for(i=pfc+1; i<=NF; i++)\
						print $i;\
					ORS="\n";\
					print "";\
				}\
			}' $infile > "$k2_message_file"
		echo "end of get message, `date `"

		t_lineno=`wc -l $k2_datetime_file | awk '{print $1}'`
		m_lineno=`wc -l $k2_message_file | awk '{print $1}'`
		check_equal $t_lineno $m_lineno \
			"日期开头的行和信息行不同，一般是日志格式不同"

		echo "start of paste datetime and message, `date `"
		paste -d ' ' $k2_datetime_file $k2_message_file > $outfile
		echo "end of paste datetime and message, `date `"

		echo "end `date `"
		echo "step finished, get"
	else
		echo "step finished, has already"
	fi
}

function step3()
{
	echo "--3--"
	infile=$1
	outfile=$2
	if [ ! -f $outfile ]
	then
		echo "start `date `"
		# 根据 session id 的正则配置规则获取每一行的 session id
		grep -Eo "$sessionidpattern1" ${infile} | grep -Eo "$sessionidpattern2" > $outfile
		check_lineno_equal $infile $outfile "有的行没有session id"

		echo "end `date `"
		echo "step finished, get"
	else
		echo "step finished, has already"
	fi
}

# 获取每一个 session id 出现的次数
function step4()
{
	echo "--4--"
	infile=$1
	outfile=$2

	if [ ! -f $outfile ]
	then
		echo "start `date `"
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
			}' $infile > $outfile

		check_lineno_equal $infile $outfile "错误"

		echo "end `date `"
		echo "step finished, get"
	else
		echo "step finished, has already"
	fi
}

# 将所有包含关键字的行按照 session 的过程分为完整的和不完整的
# 一个 session 过程包含 keywords_count 个关键字的行
# 也就是一个 session 过程包含 keywords_count 个 session id.
function step5()
{
	echo "--5--"
	infile1=$1
	infile2=$2
	outfile1=$3
	outfile2=$4

	if [ ! -f $outfile1 ]
	then
		echo "start `date `"

		tempfile="tempfile.txt"
		echo "start of paste count and datetime_message `date `"
		paste -d ' ' $infile1 $infile2 > $tempfile
		echo "end of paste count and datetime_message `date `"

		echo "start of get complete session with idcount, `date `"
		tempfile1="tempfile1.txt"
		awk -v keycount=$keywords_count '{if($1 == keycount) print $0;} ' $tempfile > $tempfile1
		echo "end of get complete session with idcount, `date `"

		echo "start of get complete session, `date `"
		cut -d ' ' -f 2- $tempfile1 > $outfile1
		echo "end of get complete session, `date `"

		echo "start of get incomplete session with idcount, `date `"
		awk -v keycount=$keywords_count '{if($1 != keycount) print $0;} ' $tempfile > $tempfile1
		echo "end of get incomplete session, with idcount `date `"

		echo "start of get incomplete session, `date `"
		cut -d ' ' -f 2- $tempfile1 > $outfile2
		echo "end of get incomplete session, `date `"

		csid=`wc -l $outfile1 | awk '{print $1}'`
		icsid=`wc -l $outfile2 | awk '{print $1}'`
		let tcsid=($csid+$icsid)
		if [ $csid'x' == 'x' ];then
			echo "ERROR, NO complete session"
			exit 1
		fi

		if [ $tcsid'x' == 'x' ];then
			echo "ERROR,5,2"
			exit 1
		fi

		tsid=`wc -l $infile1 | awk '{print $1}'`
		if [ $tsid != $tcsid ];then
			echo "ERROR,5,3"
			exit 1
		fi

		rm $tempfile $tempfile1

		echo "end `date `"
		echo "step finished, get "
	else
		echo "step finished, has already"
	fi
}

#---------------------------------------------------------------------------------

# 获取完整 session 中的每个关键字对应的所有的行
# 然后保存到以关键字命名的文件中
# get split file from k_total_session_file by keywords
function step6()
{
	echo "--6--"
	infile=$1

	k6_filename="${filename6[0]}"
	if [ ! -f "$k6_filename" ]
	then
		echo "start `date `"

		for ((i=0; i < keywords_count; i++))
		do
			grep "${keywords[$i]}" ${infile} > ${filename6[$i]}
			check "6,$keywords_count"
		done

		echo "end `date `"
		echo "step finished, get."
	else
		echo "step finished, has already."
	fi

	# 获取所有完整 session 的个数
	sid_count=`wc -l $k6_filename | awk '{print $1}'`
	echo "sid_count: $sid_count"
}

# 从关键字命名的文件中获取session id，按照关键字内部顺序排列
function step7()
{
	echo "--7--"
	outfile=$1
	if [ ! -f "$outfile" ]
	then
		echo "start `date `"

		index=0
		for ((i=0; i<keywords_count; i++))
		do
			filepath=${filename6[$i]}
			grep -Eo "$sessionidpattern1" $filepath \
				| grep -Eo "$sessionidpattern2" >> $outfile
		done

		echo "end `date `"
		echo "step finished, get ."
	else
		echo "step finished, has already."
	fi
}

# 以第一个关键字中 sessionid 出现的顺序为目标顺序
# 将其他关键字中的 sessionid 按照此顺序重排
# 获取到重排的索引
# 此处获取到的是，当前行是key，应该放到的行是值
# 期望获取的是，应该放到的行是key，当前行的值
# get resorted index of each file.
function step8()
{
	echo "--8--"
	infile=$1
	outfile=$2

	if [ ! -f "$outfile" ]
	then
		echo "start `date `"

		awk -v tcount=$sid_count '\
			{\
				if(FNR<=tcount)\
				{\
					s[$1]=FNR-1;\
					print FNR-1;\
				}\
				else\
				{\
					if (s[$1] == "" )\
						print "hello";\
					else\
						print s[$1];\
				}\
			}' $infile > $outfile

		grep -i hello $outfile > /dev/null
		if [ $? == 0 ];then
			echo "ERROR,8,1"
			exit 1
		fi

		check_lineno_equal $infile $outfile "8,错误"

		echo "end `date `"
		echo "step finished, get."
	else
		echo "step finished, has already."
	fi
}

# 获取，key 是应该放到的行，值是当前行
function step9()
{
	echo "--9--"
	infile=$1
	outfile=$2
	if [ ! -f "$outfile" ]
	then
		echo "start `date `"

		awk -v tcount=$sid_count 'BEGIN{chunk=0;linecount=0;s[0]=0;}{linecount++; key=FNR-1; value=$1; chunk=int(key/tcount); rkey=value+chunk*tcount; rvalue=key%tcount; s[rkey]=rvalue;}END{for(i=tcount;i<linecount;i++) print s[i]}' $infile > $outfile

		echo "end `date `"
		echo "step finished, get."
	else
		echo "step finished, has already."
	fi
}

# 将索引分割为以关键字命名的文件中。 
function step10()
{
	echo "--10--"
	infile1=$1
	infile2=$2

	k10_filename="${filename10[0]}"
	if [ ! -f "$k10_filename" ]
	then
		echo "start `date `"

		head -n $sid_count $infile1 > ${filename10[0]}

		for ((i=1;i<$keywords_count;i++))
		do
			let startindex=($i*$sid_count-$sid_count+1)
			let endindex=($i*$sid_count)
			sed -n "${startindex},${endindex}p" $infile2 > ${filename10[$i]}

			t_lineno=`wc -l ${filename10[$i]} | awk '{print $1}'`
			check_equal $t_lineno $sid_count "10,$i,错误"
		done

		echo "end `date `"
		echo "step finished, get."
	else
		echo "step finished, has already."
	fi
}

# 根据重排索引进行重排
# 获取不同关键字文件的行行对应
# read all file and resort it.
function step11()
{
	echo "--11--"
	k11_filename="${filename11[0]}"
	if [ ! -f "$k11_filename" ]
	then
		echo "start `date `"

		# first file, base file.
		echo "just copy first file."
		cp ${filename6[0]}  ${filename11[0]}

		echo "start of resort, `date`"
		for ((i=1; i<keywords_count; i++))
		do
			echo "in $i, start `date`"
			# put index and content paste to one file.
			tempfile="tempfile.txt"
			paste -d ' ' ${filename10[$i]} ${filename6[$i]}  > $tempfile
			# 
			echo "in $i, start of resort in awk `date`"
			awk 'BEGIN{linecount=0;}{linecount++;s[$1]=$0;}END{for(i=0;i<linecount;i++) print s[i];}' $tempfile > ${filename11[$i]}
			echo "in $i, end of resort in awk `date`"

			# remove first field of each line.
			cut -d ' ' -f 2- ${filename11[$i]} > $tempfile
			cp $tempfile ${filename11[$i]} 

			echo "in $i, end `date`"
		done
		echo "end of resort, `date`"

		rm $tempfile

		echo "end `date `"
		echo "step finished, get sorted sessionid file each keywords."
	else
		echo "step finished, has sorted sessionid file each keywords already."
	fi

}

# 获取时间字符串，
# 以下实现只计算时分秒，没有计算年月日
function step12()
{
	echo "--12--"
	k12_filename="${filename12[0]}"
	if [ ! -f "$k12_filename" ];then
		echo "start `date `"
		resultstr=""

		for ((i=0; i < keywords_count; i++))
		do
			awk '{print $1}' ${filename11[$i]} > ${filename12[$i]}
			check "$i"
			resultstr="$resultstr ${filename12[$i]}"
		done

		echo "end `date `"
		echo "step finished, get $resultstr."
	else
		echo "step finished, has $resultstr already."
	fi
}

# 将每个步骤的毫秒数按行对应的关系放置到同一文件中
function step13()
{
	echo "--13--"
	outfile=$1
	if [ ! -f "$outfile" ];then
		echo "start `date `"

		for ((i=0; i < keywords_count; i++))
		do
			wholefilelist="$wholefilelist ${filename12[$i]}"
		done
		paste $wholefilelist > $outfile

		echo "end `date `"
		echo "step finished, get."
	else
		echo "step finished, has already."
	fi
}

# 计算每个步骤的时间差
# 计算从开始那一步到此步骤的时间差
# 输出文件的时间格式示例
# t1 t2 t3 t4 d1 d2 d3 c1 c2 c3
# 其中 t* 是当前步骤的毫秒数
#      d* 是当前步到下一步的时间差，d2 是第二步到第三步的时间差
#      c* 是第一步到下一步的时间差，c2 是第一步到第三步的时间差
function step14()
{
	echo "--14--"
	infile=$1
	outfile=$2
	if [ ! -f "$outfile" ];then
		echo "start `date `"

		awk -F '\t' 'BEGIN{ORS="\t";}{ORS="\t";for(i=1;i<=NF;i++) print $i; for(i=2;i<=NF;i++) print $i-$(i-1); for(i=2;i<=NF;i++) print $i-$1;ORS="\n"; print "";}' $infile > $outfile

		echo "end `date `"
		echo "step finished, get."
	else
		echo "step finished, has already."
	fi
}

# 计算每秒每步骤执行数
function step15()
{
	echo "--15--"
	infile=$1
	outfile=$2

	if [ ! -f "$outfile" ];then
		echo "start `date `"

		awk -v keycount=$keywords_count -F '\t' '\
		BEGIN	     \
		{            \
			ORS="\t";	\
			for(f=0;f<keycount;f++)	\
			{	\
				start[f]=0;	\
				end[f]=0;	\
				total[f]=0;	\
				max[f]=0;	\
			}	\
			totals=0;	\
			totale=0;	\
		}            \
		{			 \
			for(f=1;f<=keycount;f++)	\
			{	\
				t=int($f/1000);          \
				if(totals > t || totals == 0)	\
					totals = t;	\
				if(totale < t || totale == 0)	\
					totale = t;	\
				if (start[f] > t || start[f] == 0)	\
					start[f] = t;	\
				if (end[f] < t || end[f] == 0 )	\
					end[f] = t;	\
				if (rps[t][f] == "" )			\
					rps[t][f] = 1;	\
				else	\
					rps[t][f]++;	\
			}	\
		}                   \
		END                     \
		{                   \
			for(t=totals;t<=totale;t++)	\
			{	\
				ORS="\t";	\
				for(f=1;f<=keycount;f++)	\
				{	\
					if(rps[t][f] == "")	\
						print 0;	\
					else	\
					{	\
						if(max[f] < rps[t][f])	\
							max[f] = rps[t][f];	\
						print rps[t][f];	\
						total[f] += rps[t][f];	\
					}	\
				}	\
				ORS="\n";	\
				print "";	\
			}	\
			ORS="\t";	\
			for(f=1;f<=keycount;f++)	\
				print total[f]/(end[f]-start[f]);	\
			ORS="\n";	\
			print "";	\
			ORS="\t";	\
			for(f=1;f<=keycount;f++)	\
				print max[f];	\
			ORS="\n";	\
			print "";	\
		}         \
		' $infile > ${outfile}

		echo "每秒执行数:"
		tail -n 2 ${outfile}

		echo "end `date `"
		echo "step finished, get."
	else
		echo "step finished, has already."
	fi
}

# 计算每秒的第一关键字到第n关键字之间的存活数
function step16()
{
	echo "--16--"
	infile=$1
	outfile=$2
	if [ ! -f "$outfile" ];then
		echo "start `date `"

		awk -v keycount=$keywords_count -F "\t" '    \
		BEGIN										\
		{											\
			for(f=0;f<keycount;f++)			\
			{				\
				start[f]=0;	\
				end[f]=0;	\
				totals=0;	\
				totalc=0;	\
				max[f]=0;	\
				total[f]=0;	\
			}		\
		}	\
		{	\
			for(f=2;f<=keycount;f++)	\
			{							\
				st=int($1/1000);		\
				et=int($f/1000);		\
				if(totals > st || totals == 0)	\
					totals = st;				\
				if(totale < et || totale == 0)	\
					totale = et;				\
				if (start[f] > st || start[f] == 0)		\
					start[f] = st;				\
				if (end[f] < et || end[f] == 0)	\
					end[f] = et;				\
				for(t=st;t<=et;t++)				\
				{						\
					if (tps[t][f]=="")	\
						tps[t][f] = 1;	\
					else				\
						tps[t][f]++;	\
				}				\
			}			\
		}			\
		END			\
		{			\
			for(t=totals; t<=totale; t++)	\
			{						\
				ORS="\t";			\
				for(f=2;f<=keycount;f++)	\
				{						\
					if(tps[t][f] == "" )	\
						print 0;		\
					else				\
					{					\
						if(max[f]<tps[t][f])	\
							max[f] = tps[t][f];	\
						total[f]+=tps[t][f];	\
						print tps[t][f];	\
					}			\
				}				\
				ORS="\n";		\
				print "";		\
			}					\
			ORS="\t";			\
			for(f=2;f<=keycount;f++)	\
				print total[f]/(end[f]-start[f]);	\
			ORS="\n";	\
			print "";
			ORS="\t";			\
			for(f=2;f<=keycount;f++)	\
				print max[f]; \
			ORS="\n";	\
			print "";
		}' $infile > ${outfile}

		echo "每秒存活数:"
		tail -n 2 $outfile

		echo "end `date `"
		echo "step finished, get."
	else
		echo "step finished, has already."
	fi
}

if [ $keywords_count -gt 1 ]
then
	k1_total_session_file="1_total_session.txt"
	step1 $k1_total_session_file

	k2_datetime_message_file="2_datetime_message.txt"
	step2  $k1_total_session_file $k2_datetime_message_file

	k3_sessionid_file="3_sessionid.txt"
	step3 $k2_datetime_message_file $k3_sessionid_file

	k4_sessionid_count_file="4_sessionid_count.txt"
	step4 $k3_sessionid_file $k4_sessionid_count_file

	k5_complete_session_file="5_complete_session.txt"
	k5_incomplete_session_file="5_incomplete_session.txt"
	step5  $k4_sessionid_count_file $k2_datetime_message_file \
		$k5_complete_session_file $k5_incomplete_session_file

	step6 $k5_complete_session_file

	k7_message_sessionid_file="7_message_sessionid.txt"
	step7 $k7_message_sessionid_file

	k8_wholefileindex_file="8_wholefileindex.txt"
	step8 $k7_message_sessionid_file $k8_wholefileindex_file

	k9_rwholefileindex_file="9_rwholefileindex.txt"
	step9 $k8_wholefileindex_file $k9_rwholefileindex_file

	step10 $k8_wholefileindex_file $k9_rwholefileindex_file

	step11
	step12

	# paste to one
	k13_filename="13_wholetimes.txt"
	step13 $k13_filename

	# statistic 
	k14_filename="14_wholetimes.txt"
	step14 $k13_filename $k14_filename

	# statistic
	k15_filename="15_rps.txt"
	step15 $k13_filename $k15_filename

	# statistic 
	k16_filename="16_tps.txt"
	step16 $k13_filename $k16_filename

	echo ""
	echo "完整执行的session数: $sid_count"
	echo ""
elif [ $keywords_count -eq 1 ]
then
	k1_total_session_file="1_total_session.txt"
	step1 $k1_total_session_file

	k2_datetime_message_file="2_datetime_message.txt"
	step2  $k1_total_session_file $k2_datetime_message_file

	# input of step12 is filename11 array.
	filename11[0]=$k2_datetime_message_file
	step12

	# get output of step13
	k13_filename="13_wholetimes.txt"
	cp $k2_datetime_message_file $k13_filename
	
	# statistic 
	k15_filename="15_rps.txt"
	step15 $k13_filename $k15_filename
else
	echo "ERROR, keywords_count $keywords_count"
	exit 1
fi

date 

exit 0

