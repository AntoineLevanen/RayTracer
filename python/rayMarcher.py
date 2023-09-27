import numpy as np
import matplotlib.pyplot as plt

def sphere(origin_point):
    return len(origin_point - np.array([0.0, 0.0, 2.0])) - 0.5

def march(ray_origin, ray_direction):
    
    current_point = ray_origin
    distance = 0
    scene = 0

    for i in range(50):
        current_point = ray_origin + (ray_direction * distance)
        scene = sphere(current_point) # on evalue le point dans la scene
        distance = distance + scene # on accumule la distance

        if scene < 0.001: # objet touché!
            break

        elif scene > 20.0: # on est dans le ciel!
            break
    
    return distance

def normalize(vector):
    norm = np.linalg.norm(vector)
    return np.array(vector / norm)

if __name__ == "__main__":

    resolution = [480, 720]
    image = np.zeros((resolution[0], resolution[1]))

    for u in range(resolution[0]):
        for v in range(resolution[1]):

            ray_origin = np.array([0, 0, 0]) # origine de la camera
            ray_direction = normalize(np.array([u, v, 1.0]) - ray_origin)

            distance = march(ray_origin, ray_direction)

            # distance = distance / 5.0

            image[u, v] = distance
            

    plt.imshow(image)
    plt.show()