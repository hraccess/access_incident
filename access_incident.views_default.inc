<?php
/**
 * @file
 * access_incident.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function access_incident_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'in';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Incident Map Block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Incident Map Block';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_point_location_1',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => '',
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_admin1_2' => 'field_admin1_2',
  );
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_point_location_1']['id'] = 'field_point_location_1';
  $handler->display->display_options['fields']['field_point_location_1']['table'] = 'field_data_field_point_location';
  $handler->display->display_options['fields']['field_point_location_1']['field'] = 'field_point_location';
  $handler->display->display_options['fields']['field_point_location_1']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_point_location_1']['settings'] = array(
    'data' => 'full',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
    'bureaucratic_requirement_within_' => 'bureaucratic_requirement_within_',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Access Constraints &amp; Incident Types (field_access_constraints) */
  $handler->display->display_options['filters']['field_access_constraints_tid']['id'] = 'field_access_constraints_tid';
  $handler->display->display_options['filters']['field_access_constraints_tid']['table'] = 'field_data_field_access_constraints';
  $handler->display->display_options['filters']['field_access_constraints_tid']['field'] = 'field_access_constraints_tid';
  $handler->display->display_options['filters']['field_access_constraints_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_access_constraints_tid']['expose']['operator_id'] = 'field_access_constraints_tid_op';
  $handler->display->display_options['filters']['field_access_constraints_tid']['expose']['label'] = 'Access Constraints & Incident Types';
  $handler->display->display_options['filters']['field_access_constraints_tid']['expose']['operator'] = 'field_access_constraints_tid_op';
  $handler->display->display_options['filters']['field_access_constraints_tid']['expose']['identifier'] = 'field_access_constraints_tid';
  $handler->display->display_options['filters']['field_access_constraints_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_access_constraints_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_access_constraints_tid']['vocabulary'] = 'access_constraints_incident_type';
  $handler->display->display_options['filters']['field_access_constraints_tid']['hierarchy'] = 1;

  /* Display: Incident Map Block */
  $handler = $view->new_display('block', 'Incident Map Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'map_for_incidents';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: OpenLayers Data Overlay */
  $handler = $view->new_display('openlayers', 'OpenLayers Data Overlay', 'openlayers_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_admin1_2' => 'field_admin1_2',
  );
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $translatables['in'] = array(
    t('Master'),
    t('Incident Map Block'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Location'),
    t('Access Constraints & Incident Types'),
    t('OpenLayers Data Overlay'),
  );
  $export['in'] = $view;

  $view = new view();
  $view->name = 'incidents';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Incidents';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Incidents';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_organization_affected_target_id']['id'] = 'field_organization_affected_target_id';
  $handler->display->display_options['relationships']['field_organization_affected_target_id']['table'] = 'field_data_field_organization_affected';
  $handler->display->display_options['relationships']['field_organization_affected_target_id']['field'] = 'field_organization_affected_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Field: Geographical Location */
  $handler->display->display_options['fields']['field_admin1_2']['id'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['field'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['label'] = 'Location';
  $handler->display->display_options['fields']['field_admin1_2']['delta_offset'] = '0';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Incident Date';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Responsible Actor */
  $handler->display->display_options['fields']['field_responsible_actor']['id'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['field'] = 'field_responsible_actor';
  $handler->display->display_options['fields']['field_responsible_actor']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_responsible_actor']['delta_offset'] = '0';
  /* Field: Content: Sector(s)/Cluster(s) affected */
  $handler->display->display_options['fields']['field_sectors']['id'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['table'] = 'field_data_field_sectors';
  $handler->display->display_options['fields']['field_sectors']['field'] = 'field_sectors';
  $handler->display->display_options['fields']['field_sectors']['label'] = 'Sector/Cluster';
  $handler->display->display_options['fields']['field_sectors']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_sectors']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_sectors']['multi_type'] = 'ul';
  /* Field: Content: Affected Organization */
  $handler->display->display_options['fields']['field_targetted_actor']['id'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['field'] = 'field_targetted_actor';
  $handler->display->display_options['fields']['field_targetted_actor']['label'] = 'Targetted Actor';
  $handler->display->display_options['fields']['field_targetted_actor']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_targetted_actor']['delta_offset'] = '0';
  /* Field: Taxonomy term: Type */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['relationship'] = 'field_organization_affected_target_id';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Affected Organization (field_targetted_actor) */
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['id'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['table'] = 'field_data_field_targetted_actor';
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['field'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['expose']['operator_id'] = 'field_targetted_actor_target_id_op';
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['expose']['label'] = 'Targetted Actor';
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['expose']['operator'] = 'field_targetted_actor_target_id_op';
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['expose']['identifier'] = 'field_targetted_actor_target_id';
  $handler->display->display_options['filters']['field_targetted_actor_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Responsible Actor (field_responsible_actor) */
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['id'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['table'] = 'field_data_field_responsible_actor';
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['field'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['expose']['operator_id'] = 'field_responsible_actor_target_id_op';
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['expose']['label'] = 'Responsible Actor';
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['expose']['operator'] = 'field_responsible_actor_target_id_op';
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['expose']['identifier'] = 'field_responsible_actor_target_id';
  $handler->display->display_options['filters']['field_responsible_actor_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Sector(s)/Cluster(s) affected (field_sectors) */
  $handler->display->display_options['filters']['field_sectors_tid']['id'] = 'field_sectors_tid';
  $handler->display->display_options['filters']['field_sectors_tid']['table'] = 'field_data_field_sectors';
  $handler->display->display_options['filters']['field_sectors_tid']['field'] = 'field_sectors_tid';
  $handler->display->display_options['filters']['field_sectors_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_sectors_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sectors_tid']['expose']['operator_id'] = 'field_sectors_tid_op';
  $handler->display->display_options['filters']['field_sectors_tid']['expose']['label'] = 'Sector / Cluster';
  $handler->display->display_options['filters']['field_sectors_tid']['expose']['operator'] = 'field_sectors_tid_op';
  $handler->display->display_options['filters']['field_sectors_tid']['expose']['identifier'] = 'field_sectors_tid';
  $handler->display->display_options['filters']['field_sectors_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_sectors_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sectors_tid']['vocabulary'] = 'clusters';
  $handler->display->display_options['filters']['field_sectors_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Geographical Location (field_admin1_2) */
  $handler->display->display_options['filters']['field_admin1_2_tid']['id'] = 'field_admin1_2_tid';
  $handler->display->display_options['filters']['field_admin1_2_tid']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['filters']['field_admin1_2_tid']['field'] = 'field_admin1_2_tid';
  $handler->display->display_options['filters']['field_admin1_2_tid']['value'] = '';
  $handler->display->display_options['filters']['field_admin1_2_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_admin1_2_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_admin1_2_tid']['expose']['operator_id'] = 'field_admin1_2_tid_op';
  $handler->display->display_options['filters']['field_admin1_2_tid']['expose']['label'] = 'Location';
  $handler->display->display_options['filters']['field_admin1_2_tid']['expose']['operator'] = 'field_admin1_2_tid_op';
  $handler->display->display_options['filters']['field_admin1_2_tid']['expose']['identifier'] = 'field_admin1_2_tid';
  $handler->display->display_options['filters']['field_admin1_2_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_admin1_2_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_admin1_2_tid']['vocabulary'] = 'locations';
  $handler->display->display_options['filters']['field_admin1_2_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_value']['expose']['operator_id'] = 'field_date_value_op';
  $handler->display->display_options['filters']['field_date_value']['expose']['label'] = 'Incident Date (field_date)';
  $handler->display->display_options['filters']['field_date_value']['expose']['operator'] = 'field_date_value_op';
  $handler->display->display_options['filters']['field_date_value']['expose']['identifier'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';

  /* Display: Incident */
  $handler = $view->new_display('page', 'Incident', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'incidents';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_incident');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['attach_text'] = 'Export To Excel';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'path/%/%/incident';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['incidents'] = array(
    t('Master'),
    t('Incidents'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Taxonomy term entity referenced from field_organization_affected'),
    t('Title'),
    t('Location'),
    t('Incident Date'),
    t('Responsible Actor'),
    t('Sector/Cluster'),
    t('Targetted Actor'),
    t('Type'),
    t('Sector / Cluster'),
    t('Incident Date (field_date)'),
    t('Incident'),
    t('Data export'),
  );
  $export['incidents'] = $view;

  $view = new view();
  $view->name = 'recent_incidents';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recent Incidents';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent Incidents';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'View All';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Incident Date';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field: Geographical Location */
  $handler->display->display_options['fields']['field_admin1_2']['id'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['field'] = 'field_admin1_2';
  $handler->display->display_options['fields']['field_admin1_2']['label'] = 'Location';
  /* Sort criterion: Content: Date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'access_incident' => 'access_incident',
    'br_requirement_into_country' => 'br_requirement_into_country',
    'bureaucratic_requirement_within_' => 'bureaucratic_requirement_within_',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Geographical Location (field_admin1_2) */
  $handler->display->display_options['filters']['field_admin1_2_tid']['id'] = 'field_admin1_2_tid';
  $handler->display->display_options['filters']['field_admin1_2_tid']['table'] = 'field_data_field_admin1_2';
  $handler->display->display_options['filters']['field_admin1_2_tid']['field'] = 'field_admin1_2_tid';
  $handler->display->display_options['filters']['field_admin1_2_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_admin1_2_tid']['expose']['operator_id'] = 'field_admin1_2_tid_op';
  $handler->display->display_options['filters']['field_admin1_2_tid']['expose']['label'] = 'Location';
  $handler->display->display_options['filters']['field_admin1_2_tid']['expose']['operator'] = 'field_admin1_2_tid_op';
  $handler->display->display_options['filters']['field_admin1_2_tid']['expose']['identifier'] = 'field_admin1_2_tid';
  $handler->display->display_options['filters']['field_admin1_2_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_admin1_2_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_admin1_2_tid']['vocabulary'] = 'locations';
  $handler->display->display_options['filters']['field_admin1_2_tid']['hierarchy'] = 1;

  /* Display: Recent Incidents */
  $handler = $view->new_display('block', 'Recent Incidents', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['link_url'] = 'incidents';
  $handler->display->display_options['block_description'] = 'Recent Incidents';
  $translatables['recent_incidents'] = array(
    t('Master'),
    t('Recent Incidents'),
    t('View All'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Title'),
    t('Incident Date'),
    t('Location'),
    t('more'),
  );
  $export['recent_incidents'] = $view;

  return $export;
}
