#!/bin/sh
# Obtener los grupos del usuario y formatearlos
printf $(id -nG "$FT_USER" | tr ' ' ',')
