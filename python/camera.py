import numpy as np

from ray import Ray


class Camera:

    def __init__(self, x_res, y_res, position, orientation, focal_length):
        self.x_res = x_res
        self.y_res = y_res
        self.position = position
        self.orientation = orientation
        self.focal_length = focal_length

        self.pixel_size = 0.0001

        self.image = np.zeros((self.x_res, self.y_res))
        self.image_origin = [0, 0, 0]

    def render(self, scene):
        for x_px in range(self.x_res):
            for y_px in range(self.y_res):

                # call ray marcher here

                ray = Ray(self.position, np.array([x_px * self.pixel_size, y_px * self.pixel_size, self.image_origin[2]]))
                if ray.intersection(scene):
                    self.image[x_px, y_px] = 1
                else:
                    self.image[x_px, y_px] = 0

    def updateImagePlacement(self):
        # image position in X
        image_width = self.x_res * self.pixel_size
        self.image_origin[0] = image_width / 2
        # image position in Y
        image_height = self.y_res * self.pixel_size
        self.image_origin[1] = image_height / 2
        # image position in Z
        self.image_origin[2] = self.position[2] + self.focal_length


        self.px_pos_x = []
        self.px_pos_y = []
        for x_px in range(self.x_res):
            for y_px in range(self.y_res):
                self.px_pos_x.append(-image_width / 2 + x_px * self.pixel_size)
                self.px_pos_y.append(-image_height / 2 + y_px * self.pixel_size)