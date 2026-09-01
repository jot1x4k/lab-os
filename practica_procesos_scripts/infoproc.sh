pid=$1
dir="/proc/${pid}"

if [ $# -lt 1 ]; then
    pid=0
fi

if [ "$pid" -eq 0 ]; then
    echo "Proceso [$$] (Actual)"
    echo "=============================="
    grep Name /proc/$$/status
    grep PPid /proc/$$/status
    grep State /proc/$$/status
    grep Threads /proc/$$/status
    echo "=============================="
    exit 0
fi

if [ ! -d "$dir" ]; then
    echo "No se encontró el proceso ${pid}."
    exit 1
fi

while [ "$pid" -ne 0 ]; do
    ppid=$(awk '/^PPid:/ {print $2}' /proc/$pid/status)
    echo "Proceso [${pid}]"
    echo "=============================="
    grep Name /proc/$pid/status
    grep PPid /proc/$pid/status
    grep State /proc/$pid/status
    grep Threads /proc/$pid/status
    echo "=============================="
    pid=$ppid
done

exit 0
