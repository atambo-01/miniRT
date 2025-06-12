/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_atambo.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:55:42 by atambo            #+#    #+#             */
/*   Updated: 2025/06/12 12:48:20 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ATAMBO_H
# define MINIRT_ATAMBO_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "./miniRT.h"

// color_switch.c
void	ft_color_switch(t_data *data, int key);

//dbl_utils.c
int		ft_cmp_dbl(double n1, char *op, double n2);

// exit_minirt.c
void	ft_free_obj(t_obj *obj);
void	ft_quit_mlx(t_data *data);
int		ft_exit_minirt(t_data *data);

//export_scene_obj.c
void	ft_write_obj(t_obj *obj, int fd);

//export_scene_acl.c
void	ft_write_alight(t_alight *alum, int fd);
void	ft_write_light(t_light *lum, int fd);
void	ft_write_cam(t_cam *cam, int fd);

//export.c
void	ft_write_vec3(t_vec3 v, int fd);
void	ft_write_color(t_color color, int fd);
void	ft_export_scene(t_data *data);

//ft_itoaf.c
char	*ft_ftoa(double num);

// init.c
int		ft_init_obj(t_data *data);
int		ft_init_cam(t_data *data);
int		ft_init_data(t_data *data, int fd);

// input.c
int		ft_key_hook(int keycode, t_data *data);
int		ft_mouse_hook(int button, int x, int y, t_data *data);

// input_util.c
int		ft_close_window(t_data *data);
void	ft_obj_radius(t_data *data, double i);
void	ft_obj_len(t_data *data, double i);

// rotate_obj.c
void	ft_rotate_obj_z(int key, t_obj *obj);
void	ft_rotate_obj_y(int key, t_obj *obj);
void	ft_rotate_obj_x(int key, t_obj *obj);
void	ft_rotate_obj(int key, t_obj *obj);
void 	ft_rotate_cam(int key, t_cam *cam);


// switch.c
void	ft_switch_obj_point(t_data *data, int x, int y);
void	ft_switch_obj(t_data *data);

// move_obj.c
void	ft_move_x(t_data *data, double i);
void	ft_move_y(t_data *data, double i);
void	ft_move_z(t_data *data, double i);

// minirt_error.c
size_t	ft_strlen(char const *str);
int		ft_minirt_error(char const *msg, int e);

// print_data_acl.c
void	ft_print_t_color(t_color color);
int		ft_print_cam(t_cam *cam);
int		ft_print_light(t_light *lum);
int		ft_print_alight(t_alight *lum);

// print_data.c
int		ft_print_vec3(t_vec3 *vec);
int		ft_print_cam(t_cam *cam);
int		ft_print_obj(t_obj *obj);
int		ft_print_data(t_data *data);

//ray_color.c
void	ft_ray_color(t_ray *ray, t_data *data, double x, double y);

// ray.c
void	ft_init_ray(t_data *data, t_ray *ray);
void	ft_calc_ray(int x, int y, t_ray *ray, t_cam *cam);
void	ft_ray_info(int x, int y, t_data *data);

// render_scene.c
void	ft_hit_obj_2(t_ray *ray, t_obj *obj);
void	ft_hit_obj(t_ray *ray, t_obj *obj);
void	ft_render_scene(t_data *data);
void	ft_render_and_upscale(t_data *data, int upscale);

// t_color
t_color	t_color_clamp(t_color color);
int		t_color_to_int(t_color color);

// time.c
void	ft_sleep(int sec);

// upscale_assign.c
void	ft_assign_src_coords(t_data *data, t_upscale *up, int x, int y);
void	ft_assign_corner_pixels(t_data *data, t_upscale *up);
void	ft_assign_rgb_values(t_upscale *up);
void	ft_init_neighbor(t_upscale *up, t_neighbor *nb);

// upscale_img.c
void	ft_upscale_img(t_data *data);

// util.c
void	ft_setvec3(t_vec3 *v, double a, double b, double c);
void	ft_pixel_put_img(t_img *img, int x, int y, int color);
double	ft_dot(t_vec3 a, t_vec3 b);
void	ft_normalize(t_vec3 *v);
double	ft_get_speed(struct timeval start, struct timeval end);
t_vec3	ft_vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3	ft_vec3_sub(t_vec3 v1, t_vec3 v2);
t_vec3	ft_scalar_mult(t_vec3 v1, double r);
t_vec3	ft_vec3_orthogonal(t_vec3 v);
int		ft_count_obj(t_obj *obj);
t_vec3	ft_vec3_invert(t_vec3 v);
t_vec3	ft_cross(t_vec3 a, t_vec3 b);
double	ft_vec3_mag(t_vec3 v);

// hit_light.c
t_vec3	ft_vec_ab(t_vec3 *A, t_vec3 *B);
int		ft_in_shadow(t_ray ray, t_obj *obj, double light_d);
void	ft_hit_light(t_data *data, t_ray *ray, t_light *lum);
double	ft_hit_obj_light(t_data *data, t_ray ray, t_light *lum);

// hit_obj.c
void	ft_hit_assign(double t, t_ray *ray, t_obj *obj);
void	ft_hit_plane(t_obj *obj, t_ray *ray);
void	ft_hit_sphere(t_obj *obj, t_ray *ray);
void	ft_hit_cylinder(t_obj *obj, t_ray *ray);

// obj_normal.c
void	ft_plane_normal(t_ray *ray, t_obj *pl);
void	ft_sphere_normal(t_ray *ray, t_obj *sp);
void	ft_cylinder_normal(t_ray *ray, t_obj *cy);

#endif
