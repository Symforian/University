import numpy as np
import matplotlib.pyplot as plt


class Board():
    def __init__(self, size):
        self.status = np.random.randint(2, size=size)
        self.supervisor = Supervisor(self)

    def animate(self):
        plt.ion()
        img = plt.imshow(self.status, vmin=0, vmax=1)
        while True:
            img.set_data(self.status)
            self.supervisor.supervise()
            plt.pause(0.1)
            yield self


class Supervisor():
    def __init__(self, board):
        self.status = board.status

    def get_alive_neighbors_matrix(self):
        status = self.status
        n = status[2:, 2:] + status[2:, 1:-1] + status[2:, 0:-2]
        n += status[1:-1, 2:] + status[1:-1, 0:-2] + status[0:-2, 2:]
        n += status[0:-2, 1:-1] + status[0:-2, 0:-2]
        return n

    def supervise(self):
        n_mat = self.get_alive_neighbors_matrix()
        status = self.status
        new_pix_mat = (n_mat == 3) & (status[1:-1, 1:-1] == 0)
        ret_pix_mat = ((n_mat == 2) | (n_mat == 3)) & (status[1:-1, 1:-1] == 1)
        self.status[...] = 0
        self.status[1:-1, 1:-1] |= new_pix_mat | ret_pix_mat
        return status


board = Board((20, 20))
for i in board.animate():
    pass
