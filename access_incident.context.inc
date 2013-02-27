<?php
/**
 * @file
 * access_incident.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function access_incident_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dashboard';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'taxonomy/term/690' => 'taxonomy/term/690',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-in-block' => array(
          'module' => 'views',
          'delta' => 'in-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-recent_incidents-block' => array(
          'module' => 'views',
          'delta' => 'recent_incidents-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['dashboard'] = $context;

  return $export;
}
