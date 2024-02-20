set terminal png size 500, 500
set termoption enhanced
set encoding utf8
set output 'theta_1.png'
unset key
set tics nomirror out
set border 3

set view map
set size square
unset surface
set contour
show contour
set cntrparam levels 100
set title "theta_1"
set ylabel "u.a."
set xlabel "u.a."
set clabel "*%.lf"
set isosamples 150

# length unit is angstroms
N1=1

# theta1
phi1a(x)=(1/(sqrt (pi)))*exp(- sqrt ((x-0.7)**2))
phi1b(x)=(1/(sqrt (pi)))*exp(- sqrt ((x-2.1)**2))
phi2a(y)=(1/(sqrt (pi)))*exp(- sqrt ((y-0.7)**2))
phi2b(y)=(1/(sqrt (pi)))*exp(- sqrt ((y-2.1)**2))
psi11(x)=N1*(phi1a(x)+phi1b(x))
psi12(y)=N1*(phi2a(y)+phi2b(y))

theta_1(x,y)=psi11(x)*psi12(y)

splot [0:3][0:3] theta_1(x,y)
