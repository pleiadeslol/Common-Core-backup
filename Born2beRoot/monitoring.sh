#!/bin/bash

arch=$(uname -a)

cpuf=$(cat /proc/cpuinfo | grep "physical id" | wc -l)

cpuv=$(nproc --all)
#Ram
ram_total=$(free -m | awk '$1 == "Mem:" {print $3}')
ram_use=$(free -m | awk '$1 == "Mem:" {print $2}')
ram_percent=$(free -m | awk '$1 == "Mem:" {printf("%.2f\n", $3/$2*100)}')
#Disk space
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{memory_result += $2} END {printf ("%.1fGB\n"), memory_result/1024}')
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{use += $3} END {print use}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{use += $3} {total += $2} END {printf ("%d\n"), use/total*100}')

cpul=$(vmstat 1 2 | tail -1 | awk '{print $15}')
cpu_op=$(expr 100 - $cpul)
cpu_fin=$(printf "%.1f" $cpu_op)

lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

tcpc=$(ss -ta | grep ESTAB | wc -l)

ulog=$(users | wc -w)

ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "	#Architecture: $arch
		#PU physical: $cpuf
		#vCPU: $cpuv
		#Memory Usage: $ram_use/${ram_total}MB ($ram_percent%)
		#Disk Usage: $disk_use/${disk_total} ($disk_percent%)
		#CPU load: $cpu_fin%
		#Last boot: $lb
		#LVM use: $lvmu
		#Connections TCP: $tcpc ESTABLISHED
		#User log: $ulog
		#Network: IP $ip ($mac)
		#Sudo: $cmnd cmd"