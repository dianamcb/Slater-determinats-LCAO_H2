set terminal png size 500, 500
set termoption enhanced
set encoding utf8
set output 'seno.png'
unset key
set tics nomirror out
set border 3

set view map
set size square
unset surface
set contour
show contour
set cntrparam levels 10
set title "theta_1"
set ylabel "u.a."
set xlabel "u.a."
set clabel "*%.lf"
set isosamples 150
splot [-2:2][-2:2] exp(-(x**2+y**2))*cos(x/4)*sin(y)*cos(2*(x**2+y**2))
