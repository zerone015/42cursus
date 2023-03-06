#!/bin/bash

mkdir -p srcs/requirements/nginx/tools
cp ${HOME}/secret/.env srcs
cp ${HOME}/secret/*.key ~/secret/*.crt srcs/requirements/nginx/tools
