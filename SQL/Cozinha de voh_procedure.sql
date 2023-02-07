USE VO_1;

DELIMITER //
CREATE PROCEDURE frete_gratis(IN valor_minimo float)
BEGIN
	SELECT a.Codigo_do_pedido,
		   a.valor_total,
		   c.valor as valor_frete,
		   CASE WHEN c.valor >= valor_minino then 0
		   ELSE c.valor END AS frete
	FROM Pedido a 
	LEFT JOIN Entregador b
		ON a.fk_Entregador_Codigo_do_Entregador = b.Codigo_do_Entregador
	LEFT JOIN Tipo_de_entrega c
		ON b.fk_Tipo_de_entrega_Codigo_do_transporte = c.Codigo_do_transporte
	WHERE valor_minimo = 100;
END //
DELIMITER ;