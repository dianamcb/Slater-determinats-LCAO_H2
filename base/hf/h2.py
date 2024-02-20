from pyquante2 import basisset, molecule, rhf, onee_integrals, contourplot

# conda install -c rpmuller pyquante2_pure

# Calculate H2
h2 = molecule([(1, 0.00000000,     0.00000000,     0.36628549),
               (1, 0.00000000,     0.00000000,    -0.36628549)],
               units='Angstrom')

bfs = basisset(h2, 'sto3g')         # construct basis functions
solver = rhf(h2, bfs)               # set up solver object
ens = solver.converge()             # perform scf calculation
orbe = solver.orbe                  # get MO energies
orbs = solver.orbs                  # get MO coefficients
overlap = onee_integrals(bfs, h2).S # get overlap matrix

print('Energies\n', ens)
print('Orbital energies\n', orbe)
print('Orbital coefficients\n', orbs.transpose())
print('Overlap matrix\n', overlap)