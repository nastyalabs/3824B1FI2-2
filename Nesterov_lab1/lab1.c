#include <math.h>
#include <stdio.h>

#define CHIPBOARD_DENSITY 0.0007F
#define FIBERBOARD_DENSITY 0.00075F
#define WOOD_DENSITY 0.0008F

int main() {
  printf("Enter all values in centimeters, please\n");

  float wardrobe_h = NAN;
  printf("Enter wardrobe height: ");
  scanf("%f", &wardrobe_h);

  if (wardrobe_h < 180.0F || wardrobe_h > 220.0F) {
    printf("Sorry, we can't made wardrobe with given height\n");
    return 0;
  }

  float wardrobe_w = NAN;
  printf("Enter wardrobe width: ");
  scanf("%f", &wardrobe_w);

  if (wardrobe_w < 80.0F || wardrobe_w > 120.0F) {
    printf("Sorry, we can't made wardrobe with given width\n");
    return 0;
  }

  float wardrobe_d = NAN;
  printf("Enter wardroe depth: ");
  scanf("%f", &wardrobe_d);

  if (wardrobe_d < 50.0F || wardrobe_d > 90.0F) {
    printf("Sorry, we can't made wardrobe with given depth\n");
    return 0;
  }

  float backwall_mass = (wardrobe_h * wardrobe_w * 0.5F) * FIBERBOARD_DENSITY;
  float sidewalls_mass =
      (wardrobe_h * wardrobe_d * 1.5F * 2) * CHIPBOARD_DENSITY;
  float end_mass = (wardrobe_w * wardrobe_d * 1.5F * 2) * CHIPBOARD_DENSITY;
  float doors_mass = (wardrobe_h * wardrobe_w * 1.0F) * WOOD_DENSITY;

  int shelves_number = wardrobe_h / 40;

  float check_height = wardrobe_h - 1.5F * shelves_number;
  if (check_height / 40 != shelves_number) {
    shelves_number--;
  }

  /*printf("%d\n", shelves_number);*/

  float total_shelves_mass =
      (shelves_number * 1.5F * wardrobe_d * wardrobe_w) * CHIPBOARD_DENSITY;

  float total_mass = backwall_mass + sidewalls_mass + end_mass + doors_mass +
                     total_shelves_mass;

  printf("Total mass: %f kg\n", total_mass);

  return 0;
}
