set terminal png size 500, 500
set termoption enhanced
set encoding utf8
set output '3D-theta_2.png'
unset key
set tics nomirror out
set border 3

set samples 51, 51
set style data lines
set dgrid3d 10,10
set hidden3d
set pm3d
set size square
unset surface
# set contour //contorno inferior
set cntrparam levels 100
set title "3D-theta_2"
set ylabel "u.a."
set xlabel "u.a."
set clabel "*%.lf"
set isosamples 50, 50
set palette rgb 31,22,28

# length unit is angstroms
N1=1
N2=1

# theta2
phi1a(x)=(1/(sqrt (pi)))*exp(- sqrt ((x-0.7)**2))
phi1b(x)=(1/(sqrt (pi)))*exp(- sqrt ((x-2.1)**2))
phi2a(y)=(1/(sqrt (pi)))*exp(- sqrt ((y-0.7)**2))
phi2b(y)=(1/(sqrt (pi)))*exp(- sqrt ((y-2.1)**2))
psi11(x)=N1*(phi1a(x)+phi1b(x))
psi12(y)=N1*(phi2a(y)+phi2b(y))
psi21(x)=N2*(phi1a(x)-phi1b(x))
psi22(y)=N2*(phi2a(y)-phi2b(y))

theta_2(x,y)=(1/sqrt(2))*(((psi11(x))*(psi22(y)))+((psi21(x))*(psi12(y))))

splot [0:3][0:3] theta_2(x,y)
