from pyquante2 import basisset, molecule, rhf, onee_integrals

# Calculate CO
co = molecule([(6,  0.00000000,     0.00000000,    -0.63546711),
               (8,  0.00000000,     0.00000000,     0.47832425)],
              units='Angstrom',
              name="CO")

bfs = basisset(co, 'sto3g')         # construct basis functions
solver = rhf(co, bfs)               # set up solver object
ens = solver.converge()             # perform scf calculation
orbe = solver.orbe                  # get MO energies
orbs = solver.orbs                  # get MO coefficients
overlap = onee_integrals(bfs, co).S # get overlap matrix

print('Energies\n', ens)
print('Orbital energies\n', orbe)
print('Orbital coefficients\n', orbs.transpose())
print('Overlap matrix\n', overlap)