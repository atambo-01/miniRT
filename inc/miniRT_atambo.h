/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_atambo.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <atambo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:55:42 by atambo            #+#    #+#             */
/*   Updated: 2025/05/26 19:43:57 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				MINIRT_ATAMBO_H
# define			MINIRT_ATAMBO_H

# ifndef 			BUFFER_SIZE
#  define 			BUFFER_SIZE 42
# endif

# include	"./miniRT.h"

// src/exit_minirt.c
void	ft_free_obj(t_obj *obj);
void	ft_quit_mlx(t_data *data);
int		ft_exit_minirt(t_data *data);

// src/init.c
int		ft_init_obj(t_data *data);
int		ft_init_cam(t_data *data);
int 	ft_init_data(t_data *data, int fd);

// src/input.c
int		ft_key_hook(int keycode, t_data *data);
void	ft_switch_obj(t_data *data, int x, int y);
int		ft_mouse_hook(int button, int x, int y, t_data *data);

// src/input_util.c
int		ft_close_window(t_data *data);

// src/minirt_error.c
size_t		ft_strlen(char const *str);
int			ft_minirt_error(char const *msg, int e);

// print_data.c
int		ft_print_vec3(t_vec3 *vec);
int		ft_print_cam(t_cam *cam);
int		ft_print_obj(t_obj *obj);
int		ft_print_data(t_data *data);
// ray.c
void	ft_init_ray(t_data *data, t_ray *ray);
void	ft_calc_ray(int x, int y, t_ray *ray);

// src/render_scene.c
double	ft_calc_hit_2(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj, t_hit *hit);
int		ft_calc_hit(t_ray ray, t_obj *obj, t_hit *hit);
void	ft_render_scene(t_data *data);
void	ft_render_and_upscale(t_data *data, int upscale);

//src/upscale_assign.c
void	ft_assign_src_coords(t_data *data, t_upscale *up, int x, int y);
void	ft_assign_corner_pixels(t_data *data, t_upscale *up);
void	ft_assign_rgb_values(t_upscale *up);
void	ft_init_neighbor(t_upscale *up, t_neighbor *nb);

// src/upscale_img.c
void	ft_upscale_img(t_data *data);

// src/util.c
void 	ft_setvec3(t_vec3 *v, double a, double b, double c);
void	ft_pixel_put_img(t_img *img, int x, int y, int color);
double	ft_dot(t_vec3 a, t_vec3 b);
void	ft_normalize(t_vec3 *v);
double	ft_get_speed(struct timeval start, struct timeval end);
t_vec3	ft_vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3	ft_scalar(t_vec3 v1, float r);
void	ft_hit_init(t_hit *hit);
t_vec3	ft_vec3_orthogonal(t_vec3 v);

// src/get_next_line.c && src/get_next_line_utils.c
char	*ft_strchr_1(char *s, int c);
char	*ft_strjoin_1(char *str, char *buffer);
char	*ft_strjoin_2(char *new_str, char *str, char *buffer);
char	*ft_getline(char *str);
void	ft_free(char **str, char *buffer);
char	*ft_substr_1(char *str, int start, int len_str);
char	*ft_get_next_line(int fd);

//src/hit_light.c
double	ft_in_shadow(t_ray ray, t_obj *obj, double light_d);
int		ft_hit_light(t_data *data, t_ray ray, t_hit *hit, t_light *lum);
double	ft_hit_obj_light(t_data *data, t_ray ray, t_hit hit, t_light *lum);

// src/hit_obj.c
double	ft_hit_cube(t_vec3 origin, t_vec3 dir, t_obj *obj, t_hit *hit);
double	ft_hit_plane(t_vec3 origin, t_vec3 dir, t_obj *obj, t_hit *hit);
double	ft_hit_sphere(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj, t_hit *hit);
double	ft_hit_cylinder(t_vec3 ray_o, t_vec3 ray_dir, t_obj *obj, t_hit *hit);

#endif
