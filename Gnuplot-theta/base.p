set terminal png size 500, 500
set termoption enhanced
set encoding utf8
set output 'base.png'
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

# length unit is angstroms
rA=0.5292 
rB=0.5292

# theta1
phi1=(1/sqrt (pi))*exp(-rA)
phi2=(1/sqrt (pi))*exp(-rB)
N1=1
N2=1
psi1=N1*(phi1+phi2)
psi2=N2*(phi1-phi2)
theta_1=((psi1)**2)*((psi2)**2)

splot [0:3][0:3] theta_1
