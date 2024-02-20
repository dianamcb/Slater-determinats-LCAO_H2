import orbplot.orbplotter as op

#
# The command below assumes that you have already performed the SCF calculation
# for the CO molecule. If you have not done so (or cannot remember doing so),
# please open 'co.py' (it resides in the same folder as this file) and run
# that program.
#
for i in range(0,10):
    op.plot_contour(co, orbs[:,i], bfs, plane='xz', depth=0, 
                    title='CO MO %i' % i)