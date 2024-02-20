import matplotlib.pyplot as plt
import matplotlib
import numpy as np

def plot_energies(ens):
    plt.figure(dpi=240)
    plt.plot(ens, '.-', color='black', markersize=18)
    plt.xlabel('Iterations')
    plt.ylabel('Energy [Hartree]')
    plt.show()

def plot_contour(atoms,orb,bfs,plane='xy',depth=0,npts=200,
               title="Contour plot"):
    
    if plane is 'xy':
        plot_contour_xy(atoms,orb,bfs,depth,npts,title)
        return

    if plane is 'yz':
        plot_contour_yz(atoms,orb,bfs,depth,npts,title)
        return
        
    if plane is 'xz':
        plot_contour_xz(atoms,orb,bfs,depth,npts,title)
        return
    
def plot_contour_xy(atoms,orb,bfs,depth=0,npts=200,title='Contour plot xy'):
    bbox = atoms.bbox()
    x = np.linspace(-5, 5, npts)
    y = np.linspace(-5, 5, npts)
    f = np.zeros((npts,npts),'d')
    X,Y = np.meshgrid(x,y)
    for c,bf in zip(orb,bfs):
        f += c*bf(X,Y,level)
    
    plt.figure(figsize=(4,4), dpi=240)
    ax = plt.gca()
    rrange = np.max([np.abs(np.min(f)), np.max(f)])
    levels = np.linspace(-rrange, rrange, 32)
    contours = plt.contour(X, Y, f, levels=levels, colors='black', zorder=2)
    #plt.clabel(contours, inline=True, fontsize=8)
    xlim = ax.get_xlim()
    ylim = ax.get_ylim()
    clr = plt.imshow(f, extent=[xlim[0], xlim[1], ylim[0], ylim[1]], 
                     origin='lower', interpolation='quadric')
    #ax.set_aspect(1)
    plt.title(title)
    plt.xlabel('$x$ in $\\AA$')
    plt.ylabel('$y$ in $\\AA$')
    plt.xticks(np.linspace(-5,5,5))
    plt.yticks(np.linspace(-5,5,5))
    
    for at in atoms:
        plt.text(at.r[0], at.r[1], at.tag()[0], color='white')
    
    plt.show()
    
def plot_contour_yz(atoms,orb,bfs,depth=0,npts=200,title='Contour plot yz'):
    bbox = atoms.bbox()
    y = np.linspace(-5, 5, npts)
    z = np.linspace(-5, 5, npts)
    f = np.zeros((npts,npts),'d')
    Y,Z = np.meshgrid(y,z)
    for c,bf in zip(orb,bfs):
        f += c*bf(level,Y,Z)
    
    plt.figure(figsize=(4,4), dpi=240)
    ax = plt.gca()
    rrange = np.max([np.abs(np.min(f)), np.max(f)])
    levels = np.linspace(-rrange, rrange, 32)
    contours = plt.contour(Y, Z, f, levels=levels, colors='black', zorder=2)
    #plt.clabel(contours, inline=True, fontsize=8)
    xlim = ax.get_xlim()
    ylim = ax.get_ylim()
    clr = plt.imshow(f, extent=[xlim[0], xlim[1], ylim[0], ylim[1]], 
                     origin='lower', interpolation='quadric')
    #ax.set_aspect(1)
    plt.title(title)
    plt.xlabel('$y$ in $\\AA$')
    plt.ylabel('$z$ in $\\AA$')
    plt.xticks(np.linspace(-5,5,5))
    plt.yticks(np.linspace(-5,5,5))
    
    for at in atoms:
        plt.text(at.r[1], at.r[2], at.tag()[0], color='white')
    
    plt.show()
    
def plot_contour_xz(atoms,orb,bfs,depth=0,npts=200,title='Contour plot xz'):
    bbox = atoms.bbox()
    x = np.linspace(-5, 5, npts)
    z = np.linspace(-5, 5, npts)
    f = np.zeros((npts,npts),'d')
    X,Z = np.meshgrid(x,z)
    for c,bf in zip(orb,bfs):
        f += c*bf(X,depth,Z)
    
    plt.figure(figsize=(4,4), dpi=240)
    ax = plt.gca()
    rrange = np.max([np.abs(np.min(f)), np.max(f)])
    levels = np.linspace(-rrange, rrange, 32)
    contours = plt.contour(X, Z, f, levels=levels, colors='black', zorder=2)
    #plt.clabel(contours, inline=True, fontsize=8)
    xlim = ax.get_xlim()
    ylim = ax.get_ylim()
    clr = plt.imshow(f, extent=[xlim[0], xlim[1], ylim[0], ylim[1]], 
                     origin='lower', interpolation='quadric')
    #ax.set_aspect(1)
    plt.title(title)
    plt.xlabel('$x$ in $\\AA$')
    plt.ylabel('$z$ in $\\AA$')
    plt.xticks(np.linspace(-5,5,5))
    plt.yticks(np.linspace(-5,5,5))
    
    for at in atoms:
        plt.text(at.r[0], at.r[2], at.tag()[0], color='white')
    
    plt.show()