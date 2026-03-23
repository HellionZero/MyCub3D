/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenegraph.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:05:39 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/23 18:16:13 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENEGRAPH_H
# define SCENEGRAPH_H

# include "structs.h"

void			sg_init(t_game *game);
t_scenenode		**sg_create_root(t_game *game);
t_scenenode		*sg_create_child(t_scenenode *parent, t_node_type type, void *data);
void			sg_update(t_game *game, double dt);
void			sg_render(t_game *game);
void			sg_remove_node(t_scenenode *node);
void			sg_destroy_scenegraph(t_scenenode **root);

#endif