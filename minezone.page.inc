<?php 
/**
 * Please do not commit to this project
 */

function minezone_page(){
	$nid = 2;
	$node = node_load($nid);
	
	dsm($node);
	$salida = "<h1>Titulo: $node->title</h1> " ;
	$salida .= l("Enlace al nodo", "node/$node->nid") . "<br/>";
	$salida .= "Tipo nodo: ".ucfirst($node->type)."<br/>";
	$salida .= "Fecha de creación: ".date("l/d/M/Y", $node->created) . "<br/>";
	$salida .= "Cant. Comentarios: ". $node->comment_count . "<br/>" ;
	
	if($node->comment_count == 0)
		$salida .= "Sin comentarios" . "<br/>";
	elseif ($node->comment_count == 1)
		$salida .= "Singular....Un comentario" . "<br/>";
	elseif ($node->comment_count > 1)
		$salida .= "$node->comment_count comentarios" . "<br/>";
	

	$salida .="Estado del nodo: ";
	if($node->status == 1)
		$salida .="<div style='color:#0f0;padding:10px;font-size:18px;'>Publicado</div>";
	elseif($node->status == 0)
		$salida .="<div style='color:#f00;padding:10px;font-size:18px;'>No Publicado</div>";
	$salida .= "Autor del Nodo: $node->name" . "<br/>";
	$salida .= "ir al usuario: ".l("Link" ,"user/$node->uid" );
	
	return $salida;	
}
