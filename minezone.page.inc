<?php 
/**
 * Please do not commit to this project
 */

function minezone_page(){
	$nid = 8;
	$node = node_load($nid);
	$comentarios = comment_node_page_additions($node);
	$comentarios = $comentarios["comments"];

	dsm($comentarios);
	dsm($node);

	$salida = "<h1>Titulo: $node->title</h1> " ;
	$salida .= "<table class='table table-hover'>
	    <thead>
		<th>Autor</th>
		<th>Fecha</th>
		<th>Comentario</th>
	    </thead>
	    <tbody>";

	for($id=15; $id<=19 ; $id++){
		$salida .= "<tr>
		    <td>".$comentarios[$id]["comment_body"]["#object"]->name."</td>
		    <td>".format_date($comentarios[$id]["comment_body"]["#object"]->created,'custom', 'd/M/Y')."</td>
		    <td>".$comentarios[$id]["comment_body"]["#items"][0]['value']."</td>
		</tr>";
	}	
	
	$salida .="</tbody>
	</table>";
	
	return $salida;	
}
