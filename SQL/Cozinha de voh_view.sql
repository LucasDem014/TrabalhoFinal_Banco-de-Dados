USE VO_1;

CREATE VIEW principais_cancelamentos AS
SELECT b.Codigo_de_cancelamento,
	   b.Motivo,
       count(distinct a.Codigo_do_pedido) as Pedidos
FROM Pedido a 
LEFT JOIN Cancelamento b
	ON a.fk_Cancelamento_Codigo_de_cancelamento = b.Codigo_de_cancelamento
WHERE a.Status_do_pedido = 'Cancelado'
GROUP BY 1,2
ORDER BY 3 DESC;

CREATE VIEW verificacao_valor_final AS 
WITH soma AS(
SELECT a.codigo_do_pedido,
	   round(sum(c.valor_unitario), 2) as valor
FROM Pedido a
JOIN Possui b
	ON a.Codigo_do_pedido = b.fk_Pedido_Codigo_do_pedido
JOIN Item c
	ON b.fk_Item_Codigo_do_item = c.Codigo_do_item
GROUP BY 1
)
SELECT a.codigo_do_pedido,
	   CASE WHEN  a.valor = round(b.valor_total,2) THEN 'Valores Correspondentes'
	   ELSE 'Valores não batem' END AS verificacao,
       a.valor,
       b.valor_total
FROM soma a
JOIN Pedido b
	ON a.codigo_do_pedido = b.codigo_do_pedido;


