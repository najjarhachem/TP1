#ifndef PPM_H
#define PPM_H

/*structure representant un pixel par la definition en code couleur RGB*/
struct ppm_pixel {
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

/*cette fonction sert à attribuer des valeurs au variables de la structure ppm_pixel*/
static inline void ppm_setpixel(struct ppm_pixel *px, unsigned char r,
                                unsigned char g, unsigned char b) {
  px->r = r;
  px->g = g;
  px->b = b;
}

/*structure modelisant une image qui serat un forme composée de pixels de meme couleure sur une surface definit par w et h*/
struct ppm_image {
  unsigned int width;
  unsigned int height;
  struct ppm_pixel *px;
};

/*fonction qui initialise la variable im qui pointe sur une image ,elle attribut le valeur à width et height et reserve un espace pour la future image et pour le pixel qui la forme */
int ppm_image_init(struct ppm_image *im, int w, int h);

/*liberer l'espace memopir dont l'adresse est dans im*/
int ppm_image_release(struct ppm_image *im);

/*attribut les valeurs RGB au pixel de l'image pointée par im'*/
static inline void ppm_image_setpixel(struct ppm_image *im, int x, int y,
                                      unsigned char r, unsigned char g,
                                      unsigned char b) {
  struct ppm_pixel *px = im->px + im->width * y + x;
  ppm_setpixel(px, r, g, b);
}


/*imprime l'image pointée par im sur le fichier nommé path*/
int ppm_image_dump(struct ppm_image *im, char *path);

#endif /* PPM_H */
