import matplotlib.pyplot as plt

from camera import Camera
from sphere import Sphere


if __name__ == '__main__':
    my_camera = Camera(720, 480, [0, 0, 0], [0, 0, 0], focal_length=0.050)
    my_camera.updateImagePlacement()

    my_sphere = Sphere([0, 0, 3], 0.5)

    # fig = plt.figure()
    # ax = fig.add_subplot(projection='3d')
    # ax.scatter(my_camera.position[0], my_camera.position[1], my_camera.position[2], color='r')
    # X = [my_camera.px_pos_x[0], my_camera.px_pos_x[719], my_camera.px_pos_x[719*480-719], my_camera.px_pos_x[-1]]
    # Y = [my_camera.px_pos_y[0], my_camera.px_pos_y[479], my_camera.px_pos_y[479*719-719], my_camera.px_pos_y[-1]]
    # ax.scatter(X, Y, my_camera.image_origin[2], color='b')
    # ax.scatter(my_sphere.origin[0], my_sphere.origin[1], my_sphere.origin[2], color='g')
    # plt.show()

    # image
    my_camera.render(my_sphere)
    plt.imshow(my_camera.image)
    plt.show()