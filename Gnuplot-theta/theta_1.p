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
d_a=0.8
d_b=2
# rA=sqrt((x-d)**2+(y**2))
# rB=sqrt((x)**2+(y**2))

# theta1
phi1(x,y)=(1/sqrt (pi))*exp(-(sqrt((x-d_a)**2+((y-d_a)**2))))
phi2(x,y)=(1/sqrt (pi))*exp(-(sqrt((x-d_b)**2+((y-d_b)**2))))
N1=1
N2=1
psi1(x,y)=N1*(phi1(x,y)+phi2(x,y))
psi2(x,y)=N2*(phi1(x,y)-phi2(x,y))
theta_1(x,y)=(psi1(x,y))*(psi1(x,y))

splot [0:3][0:3] theta_1(x,y)
